package com.example.test_4_1;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends Activity {//改动AppCompatActivity为Activity

    Button submit;
    Button website;
    Button home;
    Intent intent2,intent3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        submit = (Button) findViewById(R.id.submit);    //获取提交按钮
        submit.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v1) {
                String user = ((EditText) findViewById(R.id.user)).getText().toString();    //获取输入的用户
                String pwd = ((EditText) findViewById(R.id.pwd)).getText().toString();    //获取输入的密码
                String repwd = ((EditText) findViewById(R.id.repwd)).getText().toString();    //获取输入的确认密码
                String email = ((EditText) findViewById(R.id.email)).getText().toString();    //获取输入的E-mail地址
                if (!"".equals(user) && !"".equals(pwd) && !"".equals(email)) {

                    if (!pwd.equals(repwd)) {    //判断两次输入的密码是否一致
                        Toast.makeText(MainActivity.this, "两次输入的密码不一致，请重新输入！", Toast.LENGTH_LONG).show();
                        ((EditText) findViewById(R.id.pwd)).setText("");    //清空密码编辑框
                        ((EditText) findViewById(R.id.repwd)).setText("");    //清空确认密码编辑框
                        ((EditText) findViewById(R.id.pwd)).requestFocus();    //让密码编辑框获得焦点
                    } else {    //将输入的信息保存到Bundle中，并启动一个新的Activity显示输入的用户注册信息
                        Intent intent = new Intent(MainActivity.this, RegisterActivity.class);
                        Bundle bundle = new Bundle();    //创建并实例化一个Bundle对象
                        bundle.putCharSequence("user", user);    //保存用户名
                        bundle.putCharSequence("pwd", pwd);    //保存密码
                        bundle.putCharSequence("email", email);    //保存E-mail地址
                        intent.putExtras(bundle);    //将Bundle对象添加到Intent对象中
                        startActivity(intent);    //启动新的Activity

                    }
                } else {
                    Toast.makeText(MainActivity.this, "请将注册信息输入完整！", Toast.LENGTH_LONG).show();
                }

            }
        });


        website = (Button) findViewById(R.id.website_button);    //获取website按钮
        website.setOnClickListener(new ButtonListener());

            /*@Override
            public void onClick(View v3) {
                Intent intent = new Intent();// 创建Intent对象
                intent.setAction(Intent.ACTION_VIEW);// 为Intent设置动作
                intent.setData(Uri.parse("http://ci.hfut.edu.cn/2018/0821/c3995a168777/page.htm"));// 为Intent设置数据
                startActivity(intent);// 将Intent传递给Activity
            }*/


        home = (Button) findViewById(R.id.home_button);    //获取home按钮
        home.setOnClickListener(new ButtonListener());

        /*@Override
            public void onClick(View v2) {
                Intent intent_2 = new Intent();// 创建Intent对象
                intent_2.setAction(Intent.ACTION_MAIN);// 设置Intent动作
                intent_2.addCategory(Intent.CATEGORY_HOME);// 设置Intent种类
                startActivity(intent_2);// 将Intent传递给Activity
            }
        }*/
    }

    private class ButtonListener implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.home_button:
                    intent2 = new Intent(MainActivity.this, RegisterActivity.class);
                    startActivity(intent2);
                    break;
                case R.id.website_button:

                    Intent intent_3 = new Intent();// 创建Intent对象
                    intent_3.setAction(Intent.ACTION_VIEW);// 为Intent设置动作
                    intent_3.setData(Uri.parse("http://www.hfut.edu.cn/"));// 为Intent设置数据
                    startActivity(intent_3);// 将Intent传递给Activity

                    /*intent3 = new Intent(MainActivity.this, WebsiteActivity.class);
                    startActivity(intent3);*/
                    break;
            }
        }
    }
}
