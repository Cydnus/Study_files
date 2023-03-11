Create Table InventoryTB(
	productNo	varchar(45) primary key,
    ProductName varchar(45),
    Ea			int,
    Cost		int,
    Company		varchar(45),
    Etc			varchar(255)
    );
		
Create Table InputTB(
	No	int primary key,
    ProductNo	varchar(45),
    ProductName varchar(45),
    Ea			int,
    InputDate	DATE
);

Create Table OutputTB(
	No	int primary key,
	productNo	varchar(45),
    ProductName varchar(45),
    Ea			int,
    OutputDate	Date
);
		
			
	