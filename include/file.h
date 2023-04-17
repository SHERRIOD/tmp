#ifndef FILE_H
#define FILE_H

int         LoadFromFile();

int         LoadUser();
int         LoadCustomerRec();
int         LoadStock();
int         LoadInStockRec();
int         LoadOutStockRec();
int         LoadSalesRec();
int         LoadReturnRec();
int         LoadExchRec();

int         WriteToFile();

int         WriteUser();
int         WriteCustomerRec();
int         WriteStock();
int         WriteInStockRec();
int         WriteOutStockRec();
int         WriteSalesRec();
int         WriteReturnRec();
int         WriteExchRec();

#endif