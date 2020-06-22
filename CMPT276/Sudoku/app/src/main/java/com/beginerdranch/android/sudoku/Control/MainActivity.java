package com.beginerdranch.android.sudoku.Control;


import android.app.Activity;
import android.os.Bundle;

import com.beginerdranch.android.sudoku.Model.GameEngine;
import com.beginerdranch.android.sudoku.R;


public class MainActivity extends Activity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        GameEngine.getInstance().creatGrid(this);

    }


}




