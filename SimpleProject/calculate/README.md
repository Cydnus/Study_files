# Calculate 
### 진행사항    

* 2022/04/04
    - 데이터 수정 구현
        + 각각의 항목에 onChange 이벤트 지정
    - 정산 완료 버튼( 일괄 CalEnd 항목 true로 변경) 구현
    - 정산여부에 대하여 전채 분배금액 및 1인당 분배금액 값 자동 수정
    - 수정 예정 사항
        + 정산완료 버튼이나 수정단계에서 onclick 이벤트로 인한 fetch가 과다하게 발생하는점 해결 예정

    - 현재까지의 상태   
         
        <img src="Image/220405_View.gif" width="400px" title="220405_View" alt="220405_View" >


<br>

* 2022/04/04
    - 데이터 수정 버튼 클릭시 이동 화면 추가
    - 데이터 수정시 동작 미구현상태    
        + 한줄당 수정은 여러번하기 불편할 듯 하여 테이블 자체를 불러와서 변경예정
        + 해당부분에서 구현에 어려움 겪는 중 
            + 객체를 동적으로 테이블화 하다보니 받아오는 것이 어려움
            + form으로 넘겨오는것은 field가 value나 text를 지워버리는 경우가 있어 일일이 지정
            + form으로 넘겨올때 id지정이 힘듬
                + 받아오는 리스트를 모델에 추가하였지만 받아오질 못함.
   

 <br>
 
* 2022/04/03
    - 데이터 추가시 오류 발생 Alert 화면 추가
    - 데이터 추가시 보스정보(등급, 이름), 파티원 수 유지
    - 현재까지 상태   
        <img src="Image/220403_View.gif" width="400px" title="220403_View" alt="220403_View" >

 <br>
 
* 2022/04/02
    - 데이터 삽입 부분 추가
    
    - Thymeleaf 수정
        + 기존 모델에서 계산된 값을 넘겨주는 것을 클라이언트측에서 계산
    - 현재까지 상태   
        <img src="Image/220402_View.gif" width="500px" title="220402_View" alt="220402_View" >

 <br>

* 2022/04/01
    - DB 테이블 수정
        + ERD</br>
        <img src="Image/220401_ERD.PNG" width="400px"  title="220401_ERD" alt="220401_ERD"></img>
    -  전체 조회 / visible_on_table 값에 따른 조회 구현</br>
        <img src="Image/220401_View1.png" width="500px"  title="220401_View" alt="220401_View1"></img>

 <br>
 
* 2022/03/31 

    - DB설계
        + ERD</br>
        <img src="Image/220331_ERD.png" width="500px"  title="220331_ERD" alt="220331_ERD"></img>
    - Entity작성
        + Achieve
        + Boss
        + Item

