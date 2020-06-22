package com.beginerdranch.android.sudoku.Model;

import android.content.Context;

public class GameEngine {
    private static GameEngine instance;

    private GameGrid grid = null;

    private int selectedPosX = -1, selectedPosY = -1;

    private  GameEngine(){}

    public static GameEngine getInstance(){
        if(instance == null){
            instance = new GameEngine();
        }
        return instance;
    }

    public void creatGrid(Context context){
        int[][]Sudoku = SudokuGenerator.getInstance().generateGrid();
        Sudoku = SudokuGenerator.getInstance().removeElements(Sudoku);
        grid = new GameGrid(context);
        grid.setGrid(Sudoku);
    }

    public GameGrid getGrid(){
        return grid;
    }

    public void setSelectedPositon(int x, int y){
        selectedPosX = x;
        selectedPosY = y;
    }

    public void setNumber(int number){
        if(selectedPosX != -1 && selectedPosY != -1){
            grid.setItem(selectedPosX,selectedPosY,number);
        }
        grid.checkGame();
    }
}
