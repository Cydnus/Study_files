## KeyMacro Binder
---

<table>
    <tr>
        <th>진행사항</th>
        <th colspan=2></th>
    </tr>
    <tr>
        <td>22/04/24</td>
        <td>Arduino와 통신 및 버튼 동작 구현</td>
        <td>통신방식 : UART </td>
    </tr>                        
    <tr>
        <td colspan=2></td>
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