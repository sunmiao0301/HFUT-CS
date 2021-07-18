Img=imread('open.jpg');
%se=strel('square',5');%方型结构元素
se=strel('disk',5');%圆盘型结构元素
subplot(2,2,1),imshow(Img),title('开运算原始图像');
Img_open=imopen(Img,se);%直接开运算
subplot(2,2,2),imshow(Img_open),title('开运算后图像');

Img=imread('open_and_close.jpg');
%se=strel('square',5');%方型结构元素
se=strel('disk',5');%圆盘型结构元素
subplot(2,2,3),imshow(Img),title('开运算原始图像');
Img_open=imopen(Img,se);%直接开运算
subplot(2,2,4),imshow(Img_open),title('开运算后图像');