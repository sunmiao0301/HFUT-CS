Img_1=imread('expand_2.jpg');
%strel函数的功能是运用各种形状和大小构造结构元素
 se1=strel('disk',5);%这里是创建一个半径为5的平坦型圆盘结构元素
 %se=strel('square',5');%方型结构元素
corrosion_1 = imerode(Img_1,se1);
subplot(2,2,1),imshow(Img_1),title('expand_2');
subplot(2,2,2),imshow(corrosion_1),title('expand_2 腐蚀一次的结果');

Img_2=imread('corrosion.jpg');
se1=strel('disk',5);%这里是创建一个半径为5的平坦型圆盘结构元素
corrosion_1 = imerode(Img_2,se1);
corrosion_2 = imerode(corrosion_1,se1);
subplot(2,2,3),imshow(Img_2),title('corrosion_1');
subplot(2,2,4),imshow(corrosion_2),title('corrosion_1 腐蚀二次的结果');
