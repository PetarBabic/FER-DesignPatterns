#include <iostream>
#include <assert.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};
struct Shape {
    enum EType {
        circle, square, rhomb
    };
    EType type_;
};
struct Circle {
    Shape::EType type_;
    double radius_;
    Point center_;
};
struct Square {
    Shape::EType type_;
    double side_;
    Point center_;
};
struct Rhomb {
    Shape::EType type_;
    double side_;
    Point center_;
};

void drawSquare(struct Square *) {
    std::cerr << "in drawSquare\n";
}

void drawCircle(struct Circle *) {
    std::cerr << "in drawCircle\n";
}

void drawRhomb(struct Rhomb *) {
    std::cerr << "in drawRhomb\n";
}

void drawShapes(Shape **shapes, int n) {
    for (int i = 0; i < n; ++i) {
        struct Shape *s = shapes[i];
        switch (s->type_) {
            case Shape::square:
                drawSquare((struct Square *) s);
                break;
            case Shape::circle:
                drawCircle((struct Circle *) s);
                break;
            case Shape::rhomb:
                drawRhomb((struct Rhomb *) s);
                break;
            default:
                assert(0);
                exit(0);
        }
    }
}

void moveShapes(Shape **shapes, int n, int moveX, int moveY) {
    for (int i = 0; i < n; ++i) {
        struct Shape *shape = shapes[i];
        switch (shape->type_) {
            case Shape::square:
                ((struct Square *) shape)->center_.x += moveX;
                ((struct Square *) shape)->center_.y += moveX;
                break;
            case Shape::circle:
                ((struct Circle *) shape)->center_.x += moveX;
                ((struct Circle *) shape)->center_.y += moveX;
                break;
            default:
                assert(0);
                exit(0);
        }
    }
}
// ------------------OOP implementacija ----------------------------- //
class ShapeOOP {
    public:
        int x, y;

        ShapeOOP() {
            this->x = 0;
            this->y = 0;
        }

        virtual void drawShapes() = 0;

        virtual void moveShapes(int x, int y) = 0;
};

class CircleOOP:public ShapeOOP {
        int radius{};

        void drawShapes() override {
            std::cerr << "in drawCircle\n";
        }
        void moveShapes(int x, int y) override {
            this->x += x;
            this->y += y;
        }
};
class SquareOOP:public ShapeOOP {
    int side{};

    void drawShapes() override{
        std::cerr << "in drawSquare\n";
    }
    void moveShapes(int x, int y) override{
        this->x += x;
        this->y += y;
    }
};
class RhombOOP:public ShapeOOP {
    int side{};

    void drawShapes() override{
        std::cerr << "in drawRhomb\n";
    }
    void moveShapes(int x, int y) override{
        this->x += x;
        this->y += y;
    }
};
// ------------------------------------------------------------------ //

int main() {
    Shape *shapes[5];
    shapes[0] = (Shape *) new Circle;
    shapes[0]->type_ = Shape::circle;
    shapes[1] = (Shape *) new Square;
    shapes[1]->type_ = Shape::square;
    shapes[2] = (Shape *) new Square;
    shapes[2]->type_ = Shape::square;
    shapes[3] = (Shape *) new Circle;
    shapes[3]->type_ = Shape::circle;
    shapes[4] = (Shape *) new Rhomb;
    shapes[4]->type_ = Shape::rhomb;

    drawShapes(shapes, 5);

//    moveShapes(shapes, 5, 2, 3);

    ShapeOOP* s1 = new CircleOOP();
    ShapeOOP* s2 = new SquareOOP();
    ShapeOOP* s3 = new RhombOOP();

    s1->drawShapes();
    s2->drawShapes();
    s3->drawShapes();
}