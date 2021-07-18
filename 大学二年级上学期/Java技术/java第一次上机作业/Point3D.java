public class Point3D extends Point2D{
    int z;	 
    Point3D(int X,int Y,int Z){
		this.z=Z;
		this.x=X;
		this.y=Y;
}

   Point3D(Point2D p,int Z) {
		this.z=Z;
		this.x=p.x;
		this.y=p.y;
}
    
    void offset(int a, int b, int c) {
		this.x+=a;
		this.y+=b;
		this.z+=c;	
}
    
    public static void main(String[] args) {
		Point2D p2d1=new Point2D();
		Point2D p2d2=new Point2D();
		p2d1.offset(1, 1);
		p2d2.offset(2,2);
		double t1 = p2d1.x - p2d2.x;
		double t2 = p2d1.y - p2d2.y;
 		double distance = Math.sqrt(t1 * t1 + t2 * t2);

		Point3D p3d1=new Point3D(1,1,1);
		p3d1.offset(1,1,1);
		Point3D p3d2=new Point3D(p2d2,6);
        		double w1 = p3d1.x - p3d2.x;
        		double w2 = p3d1.y - p3d2.y;
        		double w3 = p3d2.z - p3d1.z;
		double distance2 = Math.sqrt(w1 * w1 + w2 * w2 + w3 * w3);
		System.out.println("两2D点的距离为："+ distance );
		System.out.println("两3D点的距离为："+ distance2);
	}
}


