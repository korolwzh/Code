package com.beginerdranch.android.sudoku.view;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.View;

public class SudokuCell extends View{

    private Paint mPaint;

    private int number;

    public SudokuCell(Context context,AttributeSet attrs){
        super(context,attrs);
        mPaint = new Paint();
    }
    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec){
        super.onMeasure(widthMeasureSpec,widthMeasureSpec);
    }

    public void setNumber(int number){
        this.number = number;

        invalidate();
    }

    //change this to show the word!!!
    @Override
    protected void onDraw(Canvas canvas){
        super.onDraw(canvas);

        mPaint.setColor(Color.BLACK);
        mPaint.setTextSize(60);

        Rect bounds = new Rect();
        mPaint.getTextBounds(String.valueOf(number),0,String.valueOf(number).length(),bounds);

        canvas.drawText(String.valueOf(number),(getWidth()-bounds.width())/2,(getHeight()+bounds.height())/2,mPaint);
    }

}
