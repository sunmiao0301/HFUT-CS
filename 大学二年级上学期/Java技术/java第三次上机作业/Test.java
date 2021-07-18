package inventory;//处理顺序：新加货单  到货单  出货单（先出少后出多） 删货单（若货未空，报错）

import java.io.*;
import java.util.*;
	
	class Inventory {
		String itemNumber;
		int quantity;
		String supplier;
		String description;
		
		public Inventory(){
			super();
		}
		public Inventory(String itemNumber,int quantity,String supplier,String description) {//存货记录包含货物编号，货物数量，供应商编号，货物描述
			super();//重新研究super具体用法
			this.itemNumber=itemNumber;		
			this.quantity=quantity;
			this.supplier=supplier;
			this.description=description;
		}	
		public Inventory(Add a) {//使用Add对象构造Inventory对象
			itemNumber = a.itemNumber;
			quantity = 0;
			supplier = a.supplier;
			description = a.description;
		}
		public void plus(int i) {
			quantity+=i;
		}
		public void minus(int i) {
			quantity-=i;
		}
	}
	
	class TransAction {//交易业务，分为发货 收货 加货 删货 此处构造函数也要super()吗
		String type;
		String itemNumber;	
		public TransAction() {
			super();
		}	
		public TransAction(String type,String itemNumber) {
			super();
			this.type=type;
			this.itemNumber=itemNumber;
		}		
	}
	
	class Order extends TransAction {//发货单有类型O，货物编号，货物数量，供应商编号
		int quantity;
		String supplier;
		public Order() {
			super();
		}
		public Order(String type,String itemNumber,int quantity,String supplier) {
			super("O",itemNumber);
			this.quantity=quantity;
			this.supplier=supplier;
		}
		public void copy(Order tmp) {
			itemNumber=tmp.itemNumber;
			type="O";
			quantity=tmp.quantity;
			supplier=tmp.supplier;
		}		
	}
	
	class Recv extends TransAction{//收货单有类型R，货物数量，供应商编号
		int quantity;
		public Recv(){
			super();
		};
		public Recv(String type,String itemNumber,int quantity) {
			super("R",itemNumber);
			this.quantity=quantity;
		}
	}
	
	class Add extends TransAction{//加货单有类型A，货物编号，货物数量，货物描述
		String supplier;
		String description;	
		public Add() {
			super();
		}
		public Add(String type,String itemNumber,String supplier,String description) {
			super("A",itemNumber);
			this.supplier=supplier;
			this.description=description;		
		}
	}	
	
	class Delete extends TransAction{//删货单有类型D，货物编号
		public Delete(String type, String itemNumber) {
			super("D", itemNumber);
		}
	} 
	
	class Error {//错误单里面有货物编号，货物数量，供应商编号（属于错误的类型有“未发送的发货记录和库存量大于0的删除记录”），由于TransAction类无法被Error类完美继承，故此类未采用继承
		String itemNumber;
		int quantity;
		String supplier;	
		public Error(String s, int i, String q) {
			itemNumber = s;
			quantity = i;
			supplier = q;
		}	
		public Error(Order o) {//使用Order对象构造Error对象
			supplier = o.supplier;
			itemNumber = o.itemNumber;
			quantity = o.quantity;
		}
	}
	
public class Test{
	static Vector<Inventory> inventory = new Vector<Inventory>();//清单，从中可读取库存记录			（TransAction.txt中有交易业务）
	static Vector<Order> order = new Vector<Order>();
	static Vector<Order> shipping = new Vector<Order>();//记录发货记录，有相同货物则合并
	static Vector<Recv> recv = new Vector<Recv>();
	static Vector<Add> add = new Vector<Add>();
	static Vector<Delete> delete = new Vector<Delete>();
	static Vector<Error> error = new Vector<Error>(); //记录错误信息


	public static void main(String[] args) throws Exception {//文件Inventory.txt  TransAction.txt  NewInventory.txt（更新的库存记录在其中）  shipping.txt  Errors.txt
		readInventory("E:\\Inventory.txt");
		readTransAction("E:\\TransActions.txt");
		doAdd();
		doReceive();
		arrOrder();
		doOrder();
		doDelete();
		write("E:\\NewInventory.txt E:\\shipping.txt E:\\Errors.txt");
	}														//处理顺序：新加货单  到货单  出货单（先出少后出多） 删货单（若货未空，报错）

	public static void readInventory(String filename)throws Exception{//处理文件"E:\\Inventory.txt"，并将其中信息放入inventory
		BufferedReader br =new BufferedReader(new FileReader(filename));
		String line=null;
		while ((line=br.readLine())!=null) {
			String tmp[]=line.split("\t");
			int quantity=Integer.parseInt(tmp[1]);//Integer.parseInt(String)的作用就是将String字符类型数据转换为Integer整型数据，遇到一些不能被转换为整型的字符时，会抛出异常。
			inventory.add(new Inventory(tmp[0],quantity,tmp[2],tmp[3]));//
		}
	br.close();
	}
	
	public static void readTransAction(String filename) throws Exception {//处理文件"E:\\Transactions.txt"，并将其中信息放入order，recv，add，delete
		BufferedReader br = new BufferedReader(new FileReader(filename));
		String line = null;
		while ((line = br.readLine()) != null) {
			String [] tmp = line.split("\t");
			if (tmp[0].equals("O")) {
				int quantity = Integer.parseInt(tmp[2]);
				order.add(new Order("O", tmp[1], quantity, tmp[3]));
			} else if (tmp[0].equals("R")) {
				int quantity = Integer.parseInt(tmp[2]);
				recv.add(new Recv("R", tmp[1], quantity));
			} else if (tmp[0].equals("A")) {
				add.add(new Add("A", tmp[1], tmp[2], tmp[3]));
			} else if (tmp[0].equals("D")) {
				delete.add(new Delete("D", tmp[1]));
			}
		}
		br.close();
	}
	
	public static void doAdd() {// 1.新加货单 
		for (int i = 0; i < add.size(); i++) {
			Inventory tmp = new Inventory(add.get(i));
			inventory.add(tmp);
		}
	}
	
	public static void doReceive() {// 2.到货单
		for (int i = 0; i < recv.size(); i++) {
			for (int j = 0; j < inventory.size(); j++) {
				String s1, s2;
				s1 = new String(recv.get(i).itemNumber);
				s2 = new String(inventory.get(j).itemNumber);
				if (s1.equals(s2)) {
					(inventory.get(j)).plus((recv.get(i)).quantity);
				}
			}
		}
	} 
		
	public static void arrOrder() {//3.将出货单按照从少到多进行排序
		for (int i = 0; i < order.size(); i++) {
			for (int j = i + 1; j < order.size(); j++) {
				if ((order.get(i)).quantity > (order.get(j)).quantity) {
					Order tmp = order.get(i);
					order.set(i, order.get(j)); // set操作：如vector.set(i,p)，将索引为i的元素置为p。
					order.set(j, tmp);
				}
			}
		}
	}
	
	public static void doOrder() {//4.出货单
		for(int i=0;i < order.size();i++) {
			for (int j = 0; j < inventory.size(); j++) {
				String s1,s2;
				s1=new String (order.get(i).itemNumber);
				s2=new String (inventory.get(j).itemNumber);
				if (s1.equals(s2)) {//注意：出货单为custom而非supplier，故只需判断itemNumber是否相同
					if(inventory.get(j).quantity>=(order.get(i)).quantity){
						(inventory.get(j)).minus((order.get(i)).quantity);
						shipping.add(order.get(i));//此处有shipping
					}else {
						Error tmp=new Error(order.get(i));
						error.add(tmp);
					}						
				}
			}
		}
	}
	
	public static void doDelete() {//5.删除货物（附加检查是否出错）
		for(int i=0;i<delete.size();i++) {
			for (int j=0;j<inventory.size();j++) {
			String s1,s2;
			s1=new String (delete.get(i).itemNumber);
			s2=new String (inventory.get(j).itemNumber);
			if (s1.equals(s2)) {
				if ((inventory.get(j)).quantity==0) {
					inventory.remove(j);
				}else {
					error.add(new Error((inventory.get(j)).itemNumber,(inventory.get(j)).quantity,(inventory.get(j)).supplier));
					}
				}
			}
		}
	}
		
	public static void arrShipping() {//6.将正确的出货单进行处理
		for (int i=0;i<shipping.size();i++) {
			for (int j=i+1;j<shipping.size();j++) {
				String s1,s2,s3,s4;
				s1=new String (shipping.get(i).itemNumber);
				s2=new String (shipping.get(j).itemNumber);
				s3=new String (shipping.get(i).supplier);
				s4=new String (shipping.get(j).supplier);
				if(s1.equals(s2)&&s3.equals(s4)) {
					Order tmp=new Order();
					tmp.copy(shipping.get(i));
					shipping.set(i,tmp);
					shipping.remove(j);
					j--;
				}
			}	
		}
		
	}
	
	public static void write(String filenames)throws Exception{
		String [] filename=filenames.split(" ");
		BufferedWriter ibw=new BufferedWriter(new FileWriter(filename[0]));
		BufferedWriter sbw=new BufferedWriter(new FileWriter(filename[1]));
		BufferedWriter ebw=new BufferedWriter(new FileWriter(filename[2]));
		for (int i=0;i<inventory.size();i++) {
			Inventory tmp=inventory.get(i);
			String s=tmp.itemNumber+"\t"+tmp.quantity+"\t"+tmp.supplier+"\t"+tmp.description;
			ibw.write(s);
			ibw.newLine();
		}
		for (int i=0;i<shipping.size();i++) {
			Order tmp=shipping.get(i);
			String s=tmp.itemNumber+"\t"+tmp.quantity+"\t"+tmp.supplier+"\t"+tmp.quantity;
			sbw.write(s);
			sbw.newLine();
		}
		for (int i=0;i<error.size();i++) {
			Error tmp=error.get(i);
			String s=tmp.itemNumber+"\t"+tmp.quantity+"\t"+tmp.supplier+"\t"+tmp.quantity ;
			ebw.write(s);
			ebw.newLine();
	}
		ibw.close();
		sbw.close();
		ebw.close();
	}
}
