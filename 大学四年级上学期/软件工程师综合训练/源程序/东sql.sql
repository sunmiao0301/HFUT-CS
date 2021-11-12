--insert into teacher(teaNo,teaName,teaDept,teaDuty,teaTitle)
--values('2018211970','李东清','计算机院','学生','助教')
--insert into teacher(teaNo,teaName,teaDept,teaDuty,teaTitle)
--values('2018211958','孙淼','计算机院','学生','助教')
--select * from teacher

--insert into project(proNo,proName,proCK,teaNo)
--values('0001','东的项目1','0','2018211970')
--insert into project(proNo,proName,proCK,teaNo)
--values('0002','东的项目2','1','2018211970')
--insert into project(proNo,proName,proCK,teaNo)
--values('0003','淼的项目1','0','2018211958')
--insert into project(proNo,proName,proCK,teaNo)
--values('0004','淼的项目2','1','2018211958')
--select * from project

--select * from adminView

 /*update project
 set proCK=0*/

--定义触发器：
--palnA
/*
create trigger audit
on project
after update
as
if(update(proCK))
begin
  declare @newproCK nchar(1),@oldproCK nchar(1)
  select @newproCK=proCK from inserted
  select @oldproCK=proCK from deleted
  if(@newproCK>@oldproCK)
    print'审批通过'
    else
    print'项目已审批，不能重复审批' 
  end
 */
 
 --planB
 /*
 
 */
 
 --更新试例：
 /*
 update project
 set proCK='1'where proNo='0003'
 */

--定义存储过程：

create procedure proStats
  as
  begin
      select
           (select COUNT(proNo) FROM project where proCK='1') finCount,
           (select COUNT(proNo) from project ) decCount;
  end


--执行存储过程：
-- exec dbo.proStats

--默认值：
/*
alter table project
add constraint proCK default '0' for proCK
*/
/*insert into project(proNo,proName,teaNo)
values('0005','东的项目1','2018211970')*/

--select * from adminView