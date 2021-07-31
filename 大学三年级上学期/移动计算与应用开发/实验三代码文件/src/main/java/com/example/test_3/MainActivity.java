package com.example.test_3;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {
    private double x,y;
    boolean canmove=false;
    boolean canmove2=false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        FrameLayout frameLayout =  findViewById(R.id.activity_main);
        final String[] array3 = new String[]{"确定","退出"};
        AlertDialog.Builder builder3 = new AlertDialog.Builder(MainActivity.this);
        builder3.setTitle("游戏有风险，进入需谨慎，真的要进入吗？").setSingleChoiceItems(array3, 0, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                if(which==0){
                    Toast.makeText(MainActivity.this,"游戏开始",Toast.LENGTH_SHORT).show();}
                else{
                    System.exit(0);
                }
                dialog.dismiss();
            }
            //setCancelable强制要求点击选项才能返回
        }).setCancelable(false).show();
        final RabbitView2 rabbitView = new RabbitView2(this);
        final TigerView2 tigerView = new TigerView2(this);
        tigerView.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:   //记录按下位置,若与图片差距20000，则向下传递
                        if (Math.pow(( x - tigerView.bitmapTX), 2) + Math.pow(( y - tigerView.bitmapTY), 2) > 20000)//判定未点击，直接返回，并传递下去
                        {
                            return true;
                        }
                        canmove2=true;   //选中该图片，移动
                        break;
                    case MotionEvent.ACTION_MOVE:
                        if(canmove2) {
                            tigerView.bitmapTX = event.getX();
                            tigerView.bitmapTY = event.getY();
                            tigerView.invalidate();  //重绘老虎组件
                            return true;
                        }
                        break;
                    case MotionEvent.ACTION_UP:
                        if (canmove2)   //NO
                        {
                            canmove2=false;
                            break;
                        }
                }
                return true;
            }
        });
        frameLayout.addView(tigerView);
        rabbitView.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:   //记录按下位置,若与图片差距20000，则向下传递
                        x = event.getX();
                        y = event.getY();
                        if (Math.pow((x - rabbitView.bitmapRX), 2) + Math.pow((y - rabbitView.bitmapRY), 2) > 20000)//判定未点击，直接返回，并传递下去
                        {
                            return false;
                        }
                        canmove=true;   //选中该图片，移动
                    case MotionEvent.ACTION_MOVE:
                        if(canmove) {
                            rabbitView.bitmapRX = event.getX();
                            rabbitView.bitmapRY = event.getY();
                            rabbitView.invalidate();  ////重绘兔子组件
                            return true;
                        }
                        break;
                    case MotionEvent.ACTION_UP:   //松开时恢复标志位
                        if (canmove)
                        {
                            canmove=false;
                            break;
                        }
                }
                return false;
            }
        });
        frameLayout.addView(rabbitView);
    }
}
