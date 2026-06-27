import java.util.ArrayList;

public class Sheet {
    private Cell[][] cells;

    public Sheet(int width, int height) {
        cells = new Cell[width][height];

        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++) {
                cells[i][j] = new Cell(this, "", 0);
            }
        }

    }

    private Cell cell(String ref) {
        return cells[refToAddress(ref, 0)][refToAddress(ref, 1)];
    }

    public void set(String ref, String content) {
        ref = ref.toLowerCase();

        Cell thisCell = cells[refToAddress(ref, 0)][refToAddress(ref, 1)];

        thisCell.setExp(content);

        if(content.matches("-?\\d+(\\.\\d+)?"))
            thisCell.setValue(Integer.parseInt(content));
        else {
            evaluate(thisCell);
            for (Cell cell : getrefs(cells[refToAddress(ref, 0)][refToAddress(ref, 1)])) {
                cell.addListener(cells[refToAddress(ref, 0)][refToAddress(ref, 1)]);
            }
        }
    }

    public ArrayList<Cell> getrefs(Cell cell) {
        ArrayList<Cell> cellList = new ArrayList<>();

        for (String s : cell.getExp().split("\\+")) {
            if(!s.matches("-?\\d+(\\.\\d+)?") && !s.isEmpty())
                cellList.add(cell(s));
        }

        return cellList;
    }
    private ArrayList<Integer> getvalues(Cell cell) {
        ArrayList<Integer> valueList = new ArrayList<>();

        for (String s : cell.getExp().split("\\+")) {
            if(s.matches("-?\\d+(\\.\\d+)?"))
                valueList.add(Integer.valueOf(s));
        }

        return valueList;
    }

    public void evaluate(Cell cell) {
        int sum = 0;

        if(checkCircularity(cell, getrefs(cell)))
            throw new RuntimeException("Error: Circular dependancy");

        for (Cell getref : getrefs(cell)) {
            sum += getref.getValue();
        }

        for (Integer getvalue : getvalues(cell)) {
            sum += getvalue;
        }

        cell.setValue(sum);
    }

    private int refToAddress(String ref, int index) {
        if(index == 0)
            return (int) ref.toLowerCase().charAt(0) - 97;
        else if(index == 1)
            return (int) ref.charAt(1) - 48 - 1;

        return -1;
    }

    private boolean checkCircularity(Cell mainCell, ArrayList<Cell> nextCells){
        if(nextCells.contains(mainCell))
            return true;
        else {
            for (Cell nextCell : nextCells) {
                return checkCircularity(mainCell, getrefs(nextCell));
            }
        }
        return false;
    }

    @Override
    public String toString() {
        char row = 'A';
        int column = 0;
        StringBuilder string = new StringBuilder();

        System.out.print("\t");
        for(int i = 1; i < cells.length + 1; i++)
            string.append(i).append("\t\t\t");
        string.append("\n");
        for(int i = 1; i < cells.length; i++)
            string.append("--------------------");

        string.append("\n");
        for (Cell[] rows : cells) {
            string.append(row).append("|").append("\t");
            for (Cell cell : rows) {
                string.append(cell).append("\t").append("|").append("\t");
            }
            string.append("\n");
            row++;
        }
        return string.toString();
    }
}
