package com.example.test_4_1;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class RegisterActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.register);	//设置该Activity中要显示的内容视图
        Intent intent=getIntent();	//获取Intent对象
        Bundle bundle=intent.getExtras();	//获取传递的数据包
        TextView user=(TextView)findViewById(R.id.user);		//获取显示用户名的TextView组件
        user.setText("用户名："+bundle.getString("user"));		//获取输入的用户名并显示到TextView组件中
        TextView pwd=(TextView)findViewById(R.id.pwd);		//获取显示密码的TextView组件
        pwd.setText("密码："+bundle.getString("pwd"));		//获取输入的密码并显示到TextView组件中
        TextView email=(TextView)findViewById(R.id.email);		//获取显示E-mail的TextView组件
        email.setText("E-mail："+bundle.getString("email"));		//获取输入的E-mail并显示到TextView组件中

    }
}

