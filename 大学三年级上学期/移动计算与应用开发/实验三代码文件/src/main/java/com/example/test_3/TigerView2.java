package com.example.test_3;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.view.View;

public class TigerView2 extends View {
    public float bitmapTX;
    public float bitmapTY;

    public TigerView2(Context context) {
        super(context);
        bitmapTX = 100;   //老虎的默认的X坐标
        bitmapTY = 100;    }
    @Override
    protected void onDraw(Canvas canvas) {
        // TODO Auto-generated method stub
        super.onDraw(canvas);
        @SuppressLint("DrawAllocation") Paint paint2 = new Paint();    //创建并实例化paint的对象
        @SuppressLint("DrawAllocation") Bitmap bitmap2 = BitmapFactory.decodeResource(this.getResources(), R.drawable.tiger);   //根据图片生成位图图像
        canvas.drawBitmap(bitmap2, bitmapTX, bitmapTY, paint2);  //画老虎
        if (bitmap2.isRecycled()) {  //判断图片是否回收
            bitmap2.recycle();
        }
    }
}
