package com.example.test_4_1;

import android.app.Activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class HomeActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);// 设置页面布局
        Button home = (Button) findViewById(R.id.home_button);// 通过ID值获得按钮对象
        home.setOnClickListener(new View.OnClickListener() {// 为按钮增加单击事件监听器

            @Override
            public void onClick(View v_2) {
                Intent intent_2 = new Intent();// 创建Intent对象
                intent_2.setAction(Intent.ACTION_MAIN);// 设置Intent动作
                intent_2.addCategory(Intent.CATEGORY_HOME);// 设置Intent种类
                startActivity(intent_2);// 将Intent传递给Activity
            }
        });
    }
}

