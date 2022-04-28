## KeyMacro Binder
---

<table>
    <tr>
        <th>진행사항</th>
        <th colspan=2></th>
    </tr>
    <tr>
        <td rowspan=2>22/04/28</td>
        <td rowspan=2>
        Arduino Pro Micro와 통신 구현
        </td>
        <td>
            통신방식 : UART
            <br>
            1byte씩 read(아두이노나 qt 둘다)
            <br>
            opcode 변경 AllLoad (1111 xxxx) -> (1010 xxxx)
            <br>
            기존 operand_header 삭제
            <br>
                  버튼 한개당 작업시 뒤에 0xff를 붙여 해당 버튼의 끝을 알림
        </td>
    </tr>
    <tr>
        <td>
        comfrim 시 완료되면 문구(QMessageBox) 추가
        <br>
        아두이노 구현 완료
        <br>
        디자인을 제외하곤 사실상 개발완료
        <br>
        <image src="resource/Running.gif">
        </td>
    </tr>
    <tr>
        <td rowspan=2>22/04/27</td>
        <td rowspan=2>
        ContextMenu 추가 / 삭제 동작 구현
        </td>
        <td>
            통신방식 : UART
            <br> 
            아두이노 대신 SerialCom 프로그램 활용 구현중
            <br>
            CR/LF 제거 ( readline->readall)
            <br>   
            시리얼 지연에 따른 처리에 문제 있을 가능성 존재
            <br>
            opcode 변경 AllLoad (1111 xxxx) -> (1100 xxxx)
        </td>
    </tr>
    <tr>
        <td>
            추가 : insertDialog 추가 / 모달로 실행
            <br>    QComboBox의 값을 MainWindow로 전달
            <br>
            삭제 : QListView 상의 셀들이 선택되어 있을 때 동작
            <br> 
            모두 Confirm 동작 이후 시리얼 전송
            <br> 
            시리얼 통신에 문제가 있음
        </td>
    </tr>
    <tr>
        <td rowspan=2>22/04/26</td>
        <td rowspan=2> 
            Reset, Confirm 버튼  동작 구현
            <br>
            / ContextMenu 추가
        </td>
        <td>
            통신방식 : UART
            <br> 
            아두이노 대신 SerialCom 프로그램 활용  구현중
            <br>
            opcode 변경 setMode (0000 xxxx) -> (0011 xxxx)
        </td>
    </tr>
    <tr>
        <td>
            Reset : 기존의 변경사항 무시
            <br>
            Confirm : 시리얼로 해당 버튼에 맞는 값 전송(setMode)
        </td>
    </tr>
    <tr>
        <td>22/04/25</td>
        <td> Serial read 동작 구현</td>
        <td>통신방식 : UART <br> 아두이노 대신 SerialCom 프로그램 활용  구현중 </td>
    </tr>
    <tr>
        <td rowspan=2>22/04/24</td>
        <td rowspan=2>Arduino와 통신 및 버튼 동작 구현</td>
        <td>통신방식 : UART </td>
    </tr>                        
    <tr>
        <td>
            0xC0 Opcode Operand_Header Operand 0xC0 
            <br>Opcode : (8bit) AllLoad(1111 xxxx ), setMode(0000 xxxx:0~11,13,14)  LF
            <br>Operand_Header : (8bit) Count of Operand empty : 0x00
            <br>하지만 사용중인 promicro에서 serial read & write 동작 안함.(우노에선 동작확인)
            <br>아두이노 자체 시리얼 모니터에서는 동작 하지만 그외엔 동작안함.
        </td>
    </tr>
    <tr>
    <td>22/04/23</td>
    <td>UI 및 Connect구현</td>
    <td></td>
    </tr>
    <tr>
    <td>22/04/22</td>
    <td>프로젝트 생성</td>
    <td></td>
    </tr>
</table>