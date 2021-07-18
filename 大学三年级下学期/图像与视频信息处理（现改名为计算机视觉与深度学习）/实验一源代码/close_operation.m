Img=imread('close.jpg');
%se=strel('square',5');%方型结构元素
se=strel('disk',5');%圆盘型结构元素
subplot(2,2,1),imshow(Img),title('闭运算原始图像');
Img_close=imclose(Img,se);%直接开运算
subplot(2,2,2),imshow(Img_close),title('闭运算原始图像');

Img=imread('open_and_close.jpg');
%se=strel('square',5');%方型结构元素
se=strel('disk',5');%圆盘型结构元素
subplot(2,2,3),imshow(Img),title('闭运算原始图像');
Img_close=imclose(Img,se);%直接开运算
subplot(2,2,4),imshow(Img_close),title('闭运算原始图像');