# SimpleProjetes
## Calcualte 
* 개요  
자주 플레이하는 게임 "메이플스토리" 에서 보스 레이드시 분배금을 자동화 시켜 처리하자는 생각에 작성하게됨.</br></br>
기존 엑셀 작업 또는 C# (With DB(MongoDB), 파일 기반 ) 으로 작성한 것을 사용중이지만, 여러가지 문제점이 발생하였다.</br>
엑셀의 경우 일일이 입력사항에 대한 번거로움이 존재 하였고, 데이터의 양이 늘어남에 따라 작업 시간이 오래 걸린다는 단점이 있었다. </br>
이를 해결하기 위하여 C#으로 코드를 작성하였으며, 처음 DB기반으로 작성하였다. </br>  
라즈베리파이(DB)의 간혈적인 전원 끊김과</br>
잘못 입력된 항목에 대한 수정의 불편함으로 인하여 파일 기반으로 변경하였다.</br></br>
하지만 원인불명의 프로그램 종료(디버깅에서는 동작 잘만되더니 왜...)등의 불편함 및 최근 학습한 Spring Framework & JPA를 기반으로 하여 웹 기반으로 작성하려 시작함.

-------
* 진행사항
>|   날자   |    항목    |비고|
>|   :-:    |   :-:      |-|
>|2022/03/31| DB 구조 설계, 기본적인 Entity 설계|프로젝트 시작일|
>| ||
>|||

--------
* Using Modules
> <table>
>    <tr>
>        <td> Language  </td>
>        <td colspan=2> JAVA 11 (Maven Project)  </td>
>    </tr>
>    <tr>
>        <td></td>
>        <td> Module </td>
>        <td> Spring Boot V. 2.6.5 </td>
>    </tr>    
>    <tr>
>      <td></td>
>        <td> </td>
>        <td> ( Lombok, JPA ) </td>
>    </tr>
>    <tr>
>        <td>Database </td>
>        <td> MariaDB </td>
>        <td> on Raspberry Pi 3B+ </td>
>    </tr>
>    <tr>
>   <td> IDE </td>
>   <td colspan=2>IntelliJ IDEA 2021.3.3 (Community Edition)</td>
>    </tr>
></table>
