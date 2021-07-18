Img=imread('Lena.jpg'); 
subplot(2,2,1),imshow(Img),title('原始图像');
[n,m,a]=size(Img);%判断图像的大小
GrayImage=zeros(n,m);
for x=1:n%通过双循环对图像进行灰度化处理
    for y=1:m
    GrayImage(x,y)=0.3*Img(x,y,1)+0.59*Img(x,y,2)+0.11*Img(x,y,3);%加权实现灰度化 
    end
end
subplot(2,2,2),imshow(uint8(GrayImage)),title('加权灰度化');
