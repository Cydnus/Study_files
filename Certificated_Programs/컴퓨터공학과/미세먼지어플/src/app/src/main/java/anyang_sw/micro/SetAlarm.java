/*
미세먼지 알림 프로그램
    알람 설정 부분
        작성자 : 조상호

        작성일 : 2018.12.07

        구조 ; 이 프로그램은 다음과 같은 클래스로 구성되어있음
            SetAlarm : 알람설정과 관련된 클래스
                메소드
                onCreate : 알람설정하는 메소드 / 주로 버튼에 따른 이벤트처리 담당.

        공유 변수
                MainActivity.alarmTime : 알람시간에 대한 정보 저장 "(시):(분)" 과같은 방식으로 저장되어있는 Arraylist

        외부 참조 파일
        alarm.txt : 즐겨찾기에 대한 정보 / 위치값("경기 안양시")으로 한줄씩 저장.

 */



package anyang_sw.micro;

import android.app.TimePickerDialog;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TimePicker;
import android.widget.Toast;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;

public class SetAlarm extends AppCompatActivity {

    private TimePickerDialog.OnTimeSetListener listener;
    int positions;
   ArrayList<String> alarm;
    TimePickerDialog dialog;

    ArrayAdapter adapter;
    ArrayList<String> items;
    boolean click;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_alarm);

        alarm = MainActivity.alarmTime;

        //파일 입출력으로 설정

       click = true;


       items = new ArrayList<String>() ;
        // ArrayAdapter 생성. 아이템 View를 선택(single choice)가능하도록 만듦.

        for(int i = 0; i<alarm.size();i++){
            items.add(alarm.get(i));
        }



         adapter = new ArrayAdapter(this, android.R.layout.simple_list_item_single_choice, items) ;

        // listview 생성 및 adapter 지정.

        final ListView listview = (ListView) findViewById(R.id.alarmlist) ;



        listview.setAdapter(adapter) ;
        Button insert = findViewById(R.id.set) ;
        insert.setOnClickListener(new Button.OnClickListener() {
            public void onClick(View v) {
                //추가
                    click = false;
                    int count;
                    count = adapter.getCount();
                    if(count <5) {
                        // 아이템 추가.
                        alarm.add("-1:-1");
                        items.add("두번 탭하여 시간을 설정하여 주세요");
                        // listview 갱신
                        adapter.notifyDataSetChanged();
                    }
                    else{
                        Toast.makeText(getApplicationContext(), "더 이상 추가 가능한 공간이 없습니다.", Toast.LENGTH_SHORT).show();
                    }


            }
        }) ;



        Button delete = (Button)findViewById(R.id.delete) ;
        delete.setOnClickListener(new Button.OnClickListener() {
            public void onClick(View v) {
                //삭제
                int count, checked ;
                count = adapter.getCount() ;
                click = false;
                if (count > 0) {
                    // 현재 선택된 아이템의 position 획득.
                    checked = listview.getCheckedItemPosition();

                    if (checked > -1 && checked < count) {
                        // 아이템 삭제
                        items.remove(checked) ;

                        // listview 선택 초기화.
                        listview.clearChoices();

                        alarm.remove(checked);
                        File file = new File(getFilesDir()+"/alarm.txt") ;
                        FileWriter fw=null;
                        BufferedWriter bw=null;
                        try{
                            fw = new FileWriter(file);
                            bw = new BufferedWriter(fw);

                            for (int i = 0; i < items.size(); i++) {
                                bw.write(items.get(i));
                                bw.write("\n");
                                bw.flush();
                            }
                        }catch(Exception e){
                            e.printStackTrace();
                        }
                        try {
                            if (bw != null)
                                bw.close();
                            if (fw != null)
                                fw.close();
                        }
                        catch(Exception e){
                            e.printStackTrace();
                        }
                        // listview 갱신.
                        adapter.notifyDataSetChanged();
                    }
                }
            }


        }) ;


        listener= new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker view, int hourOfDay, int minute) {

// 설정버튼 눌렀을 때
                alarm.set(positions,hourOfDay+":"+minute);
                items.set(positions,alarm.get(positions));
                adapter.notifyDataSetChanged();
                Toast.makeText(getApplicationContext(), hourOfDay + "시 " + minute + "분", Toast.LENGTH_SHORT).show();
                File file = new File(getFilesDir()+"/alarm.txt") ;
                FileWriter fw=null;
                BufferedWriter bw=null;
                try{
                fw = new FileWriter(file);
                bw = new BufferedWriter(fw);

                for (int i = 0; i < items.size(); i++) {
                    bw.write(items.get(i));
                    bw.write("\n");
                    bw.flush();
                }
            }catch(Exception e){
                e.printStackTrace();
            }
            try {
                if (bw != null)
                    bw.close();
                if (fw != null)
                    fw.close();
            }
            catch(Exception e){
                e.printStackTrace();
                    }
            }

        };
        listview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            int lastpick= -1;
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                //setTimer
                if(lastpick == position&&click) {
                    positions = position;
                    dialog = new TimePickerDialog(SetAlarm.this, listener, 15, 24, true);
                    dialog.show();
                }
                else{
                    click = true;
                    lastpick = position;
                }
            }
        });
    }


}
