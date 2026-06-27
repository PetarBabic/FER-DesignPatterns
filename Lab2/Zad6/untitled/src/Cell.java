import java.util.ArrayList;

public class Cell {
    private String exp;
    private Integer value;
    private Sheet sheet;
    private ArrayList<Cell> listeners = new ArrayList<>();

    public Cell(Sheet sheet, String exp, int value) {
        this.sheet = sheet;
        this.exp = exp;
        this.value = value;
    }

    public Cell(String exp, int value) {
        this.exp = exp;
        this.value = value;
    }

    public Cell(Sheet sheet, String exp) {
        this.sheet = sheet;
        this.exp = exp;
    }

    public Cell(String exp) {
        this.exp = exp;
    }

    public void setValue(int value) {
        boolean push = false;

        if(this.value != null && this.value != value)
            push = true;

        this.value = value;
        if(push)
            listeners.forEach(l -> sheet.evaluate(l));
    }

    public void setExp(String exp) {
        if(!this.exp.isBlank())
            sheet.getrefs(this).forEach(ref -> ref.removeListener(this));

        this.exp = exp;

    }
    public String getExp() {
        return exp;
    }
    public int getValue() {
        sheet.evaluate(this);

        return value;
    }

    public void addListener(Cell listener) {
        this.listeners.add(listener);
    }
    public void removeListener(Cell listener) {
        this.listeners.remove(listener);
    }

    @Override
    public String toString() {
        return String.valueOf(exp + " - " + value);
    }
}
