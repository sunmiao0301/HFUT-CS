package com.example.test;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.Html;
import android.text.SpannableString;
import android.text.Spanned;
import android.text.style.AbsoluteSizeSpan;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //设置"用户名"提示文字的大小
        EditText etUserName = (EditText)findViewById(R.id.editTextNumber2);
        SpannableString s = new SpannableString("QQ号码/手机/邮箱");
        AbsoluteSizeSpan textSize = new AbsoluteSizeSpan(14,true);
        s.setSpan(textSize,0,s.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
        etUserName.setHint(s);

        //设置"密码"提示文字的大小
        EditText etPassword = (EditText)findViewById(R.id.editTextTextPassword4);
        //用html的方式来设置这个属性,毕竟都是String
        etPassword.setHint(Html.fromHtml("<font color=\"\"><small>密码</small></font>"));
        //etPassword.setHint(Html.fromHtml("<font color=\"\"><small><small>密码</small></small></font>"));与QQ界面对比后发现color就使用默认值灰色很好
    }
}

