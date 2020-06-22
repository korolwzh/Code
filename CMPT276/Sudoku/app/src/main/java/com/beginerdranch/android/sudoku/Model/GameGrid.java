package com.beginerdranch.android.sudoku.Model;

import android.content.Context;
import android.graphics.Color;
import android.widget.Toast;

import com.beginerdranch.android.sudoku.R;
import com.beginerdranch.android.sudoku.View.SudokuCell;

public class GameGrid {
    private SudokuCell[][] Sudoku = new SudokuCell[9][9];

    private Context context;

    public GameGrid(Context context){
        this.context = context;
        for(int x=0;x<9;x++){
            for(int y=0;y<9;y++){
                Sudoku[x][y]= new SudokuCell(context);
            }
        }
    }


    public SudokuCell getItem(int x,int y){
        return Sudoku[x][y];
    }

    public SudokuCell getItem(int position){
        int x = position%9;
        int y = position/9;

        return Sudoku[x][y];
    }
    //set pre-fill color
    public void inner(int xRegion, int yRegion) {
        for(int xPos=xRegion*3;xPos<xRegion*3+3;xPos++) {
            for (int yPos = yRegion * 3; yPos < yRegion * 3 + 3; yPos++) {
                if(xRegion == 0 && yRegion == 0){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.RED);
                }
                else if (xRegion == 1 && yRegion == 0){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.BLUE);
                } else if (xRegion == 2 && yRegion == 0){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.GREEN);
                }
                if(xRegion == 1 && yRegion == 1){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.RED);
                }
                else if (xRegion == 2 && yRegion == 1){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.BLUE);
                } else if (xRegion == 0 && yRegion == 1){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.GREEN);
                }
                if(xRegion == 2 && yRegion == 2){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.RED);
                }
                else if (xRegion == 0 && yRegion == 2){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.BLUE);
                } else if (xRegion == 1 && yRegion == 2){

                    Sudoku[xPos][yPos].setBackgroundColor(Color.GREEN);
                }
            }
        }
    }

    public void setGrid(int [][] grid) {

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                inner(x, y);
            }
        }

        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                Sudoku[x][y].setInitValue(grid[x][y]);

                if(grid[x][y] != 0 ){
                    Sudoku[x][y].setNotModifiable();
                } else {
                    Sudoku[x][y].setBackgroundColor(Color.WHITE);
                    Sudoku[x][y].setBackgroundDrawable(context.getDrawable(R.drawable.cell));
                }
            }
        }
    }


    public void setItem(int x, int y, int number){
        Sudoku[x][y].setValue(number);
    }

    public void checkGame(){
        int[][] sudukoGrid = new int[9][9];
        for(int x=0;x<9;x++){
            for(int y=0;y<9;y++){
                sudukoGrid[x][y] = getItem(x,y).getValue();
            }
        }
        if(SudokuChecker.getInstance().checkSudoku(sudukoGrid)){
            Toast.makeText(context,"You solved the sudoku.",Toast.LENGTH_LONG).show();
        }
    }
}
