Img_1=imread('expand_1.jpg');
B=[0 1 0
1 1 1
0 1 0];
expand_1=imdilate(Img_1,B);%图像1被结构元素B膨胀
subplot(2,2,1),imshow(Img_1),title('expand_1');
subplot(2,2,2),imshow(expand_1),title('expand_1 膨胀一次的结果');

Img_2=imread('expand_2.jpg');
B=[0 1 0
1 1 1
0 1 0];
expand_1=imdilate(Img_2,B);%图像1被结构元素B膨胀
expand_2=imdilate(expand_1,B);%图像1被结构元素B膨胀
expand_3=imdilate(expand_2,B);%图像1被结构元素B膨胀
subplot(2,2,3),imshow(Img_2),title('expand_2');
subplot(2,2,4),imshow(expand_3),title('expand_2膨胀三次的结果');