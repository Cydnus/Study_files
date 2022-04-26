## KeyMacro Binder
---

<table>
    <tr>
        <th>진행사항</th>
        <th colspan=2></th>
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
            아두이노 대신 SerialCom 프로그램 활용 
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
        <td>통신방식 : UART <br> 아두이노 대신 SerialCom 프로그램 활용 </td>
    </tr>
    <tr>
        <td rowspan=2>22/04/24</td>
        <td rowspan=2>Arduino와 통신 및 버튼 동작 구현</td>
        <td>통신방식 : UART </td>
    </tr>                        
    <tr>
        <td>
            0xC0 Opcode Operand_Header Operand 0xC0 
            <br>Opcode : (8bit) AllLoad(1111 xxxx ), setMode(0000 xxxx:0~11,13,14) 
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