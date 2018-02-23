set PROGRAM="%~1"

REM запуск программы без параметров           
REM %PROGRAM%                            
REM IF NOT ERRORLEVEL 1 GOTO err  

REM запуск программы с пустой строкой в качестве одного из параметров 
REM %PROGRAM% ""   
REM IF NOT ERRORLEVEL 1 GOTO err  

REM запуск программы с несуществующим названием input файла
REM %PROGRAM% inputNotExist.txt output.txt 
REM IF NOT ERRORLEVEL 1 GOTO err  

REM запуск теста 0 
Release\1_6.exe test\0.txt output.txt                                  
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\0Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\61.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\61Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\1111.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\1111Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\6663.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\6663Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\500552.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\500552Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\611443.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\611443Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\66666666.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\66666666Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\100000000.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\100000000Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\6220011333.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\6220011333Out.txt 
IF ERRORLEVEL 1 GOTO err 

REM запуск теста 61 
Release\1_6.exe test\6445555223322222.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\6445555223322222Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\6660066000000000.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\6660066000000000Out.txt 
IF ERRORLEVEL 1 GOTO err 

REM запуск теста 61 
Release\1_6.exe test\6445555552233222222000055444.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\6445555552233222222000055444Out.txt 
IF ERRORLEVEL 1 GOTO err  

REM запуск теста 61 
Release\1_6.exe test\64455555522333322222200000055444.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\64455555522333322222200000055444Out.txt 
IF ERRORLEVEL 1 GOTO err 

REM запуск теста 61 
Release\1_6.exe test\666665566446633662266116600006.txt output.txt                                   
IF ERRORLEVEL 1 GOTO err 
FC output.txt test\666665566446633662266116600006Out.txt 
IF ERRORLEVEL 1 GOTO err 

                           
ECHO Program testing succeeded :-)                  
EXIT                                                
:err                                                
ECHO Program testing failed :-(                     
EXIT