package com.beginerdranch.android.sudoku;

import java.util.ArrayList;
import java.util.Random;

public class SudokuGenerator {

    private static SudokuGenerator instance;

    private  ArrayList<ArrayList<Integer>> Avalible = new ArrayList<ArrayList<Integer>>();

    private SudokuGenerator() {}

    private Random rand = new Random();

    public static SudokuGenerator getInstance() {
        if (instance == null) {
            instance = new SudokuGenerator();
        }
        return instance;
    }

//change the constructor for the word!!!
    public int[][] generateGrid(){

        int[][] Sudoku = new int[9][9];

        int currentPos = 0;

        clearGrid(Sudoku);

        while(currentPos < 81){
            if(Avalible.get(currentPos).size() != 0){

                int i= rand.nextInt(Avalible.get(currentPos).size());
                int number = Avalible.get(currentPos).get(i);

                if(!checkConflict(Sudoku,currentPos,number)){
                    int xPos = currentPos%9;
                    int yPos = currentPos/9;
                    Sudoku[xPos][yPos] = number;
                    Avalible.get(currentPos).remove(i);
                    currentPos++;
                }
                else{
                    Avalible.get(currentPos).remove(i);
                }
            }
            else{
                for(int i =1; i<=9; i++) {
                    Avalible.get(currentPos).add(i);
                }
                currentPos--;
            }
        }
        return Sudoku;
    }

    private void clearGrid(int[][] Sudoku){
        Avalible.clear();
        for(int y=0;y<9;y++){
            for(int x=0;x<9;x++){
                Sudoku[x][y] = -1;
            }
        }
        for(int x=0; x<81; x++){
            Avalible.add(new ArrayList<Integer>());
            for(int i=1;i<=9;i++){
                Avalible.get(x).add(i);
            }
        }
    }

//if return ture, there is conflict.
    private boolean checkConflict ( int[][] Sudoku, int currentPos,final int number){
        int xPos = currentPos % 9;
        int yPos = currentPos / 9;



        if(checkHorizontalConflict(Sudoku,xPos,yPos,number))
            return true;
        else if(checkVerticalConflict(Sudoku,xPos,yPos,number))
            return true;
        else if(checkRegionConflict(Sudoku,xPos,yPos,number))
            return true;

        return false;

    }

    private  boolean checkHorizontalConflict(final int[][] Sudoku,final int xPos, final int yPos, final int number){
        for(int x=xPos-1; x>=0; x--){
            if(number == Sudoku[x][yPos])
                return true;
        }
        return false;
    }

    private  boolean checkVerticalConflict(final int[][] Sudoku,final int xPos, final int yPos, final int number){
        for(int y=yPos-1; y>=0; y--){
            if(number == Sudoku[xPos][y])
                return true;
        }
        return false;

    }

    private  boolean checkRegionConflict(final int[][] Sudoku,final int xPos, final int yPos, final int number){

        int xRegion = xPos/3;
        int yRegion = yPos/3;

        for(int x=xRegion*3; x < xRegion*3+3; x++){
            for(int y=yRegion*3 ;y < yRegion*3+3; y++){
                if((x != xPos || y != yPos )&& number == Sudoku[x][y])
                    return true;
            }
        }
        return false;
    }
}