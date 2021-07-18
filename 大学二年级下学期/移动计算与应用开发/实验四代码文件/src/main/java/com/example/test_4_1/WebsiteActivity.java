package com.example.test_4_1;

import android.os.Bundle;
import android.content.Intent;
import android.net.Uri;
import android.view.View;
import android.widget.Button;
import android.app.Activity;

public class WebsiteActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = (Button) findViewById(R.id.website_button);// 通过ID值获得按钮对象
        button.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v_3){
                /*Intent intent_3 = new Intent();// 创建Intent对象
                intent_3.setAction(Intent.ACTION_VIEW);// 为Intent设置动作
                intent_3.setData(Uri.parse("http://www.hfut.edu.cn/"));// 为Intent设置数据
                startActivity(intent_3);// 将Intent传递给Activity*/
            }
        });
    }
}


