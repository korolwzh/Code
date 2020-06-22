package com.beginerdranch.android.sudoku.View;

import android.app.Activity;
import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.GridView;

import com.beginerdranch.android.sudoku.Control.NumberButton;
import com.beginerdranch.android.sudoku.R;

public class ButtonsGridView extends GridView {

    public ButtonsGridView(Context context, AttributeSet attrs){
        super(context, attrs);

        ButtonGridViewAdapter gridViewAdapter = new ButtonGridViewAdapter(context);

        setAdapter(gridViewAdapter);
    }

    class ButtonGridViewAdapter extends BaseAdapter{

        private Context context;

        public ButtonGridViewAdapter(Context context){
            this.context = context;
        }


        @Override
        public int getCount() {
            return 10;
        }

        @Override
        public Object getItem(int position) {
            return null;
        }

        @Override
        public long getItemId(int position) {
            return position;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            View v= convertView;

            if(v==null){
                LayoutInflater inflater = ((Activity) context).getLayoutInflater();
                v = inflater.inflate(R.layout.button,parent,false);

                NumberButton button;
                button = (NumberButton)v;
                button.setTextSize(10);
                button.setId(position);

                if(position != 9){
                    button.setText(String.valueOf(position+1));
                    button.setNumber(position+1);
                }
                //when delete the number make it to the 0;
                else{
                    button.setText("Delete");
                    button.setNumber(0);
                }
                return button;
            }

            return v;
        }
    }
}
