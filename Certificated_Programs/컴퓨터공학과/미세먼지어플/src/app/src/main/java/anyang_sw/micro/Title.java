/*
미세먼지 알림 프로그램
    title : 로딩부분
        작성자 : 조상호

        작성일 : 2018.12.07

        구조 ; 이 프로그램은 다음과 같은 클래스로 구성되어있음
               Title : MainActivity 로 4초 이후 넘겨주는 클래스

 */

package anyang_sw.micro;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import java.util.*;

public class Title extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_title);


        TimerTask tt = new TimerTask(){
            @Override
            public void run() {
                 startActivity(new Intent(getApplicationContext(), MainActivity.class));
                finish();
            }
        };
        Timer time = new Timer();
        time.schedule(tt,4000);
     //  closeContextMenu();
    }

}
