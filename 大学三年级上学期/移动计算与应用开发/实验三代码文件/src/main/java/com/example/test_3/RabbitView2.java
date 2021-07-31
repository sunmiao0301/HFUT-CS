package com.example.test_3;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.view.View;

public class RabbitView2 extends View {
    public float bitmapRX;
    public float bitmapRY;

    public RabbitView2(Context context) {
        super(context);
        bitmapRX = 200;   //小兔子的默认的X坐标
        bitmapRY = 200;    }
    @Override
    protected void onDraw(Canvas canvas) {
        // TODO Auto-generated method stub
        super.onDraw(canvas);
        @SuppressLint("DrawAllocation") Paint paint1 = new Paint();    //创建并实例化paint的对象
        @SuppressLint("DrawAllocation") Bitmap bitmap1 = BitmapFactory.decodeResource(this.getResources(), R.drawable.rabbit);   //根据图片生成位图图像,改换mipmap？
        canvas.drawBitmap(bitmap1, bitmapRX, bitmapRY, paint1);  //画小兔子
        if (bitmap1.isRecycled()) {  //判断图片是否回收
            bitmap1.recycle();
        }
    }
}
