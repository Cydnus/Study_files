/*
미세먼지 알림 프로그램
    서비스 설정(종료시 작업)
        작성자 : 조상호

        작성일 : 2018.12.07

        구조 ; 이 프로그램은 다음과 같은 클래스로 구성되어있음
            TestService : 알람설정과 관련된 클래스
                메소드
                    onBind : 바로 종료가 아닌 거쳐서 종료하기 위해 null 설정
                    onTaskRemoved : 파일 저장을 위한 메소드

        공유 변수
               ArrayList<String> staticItems : 즐겨찾기 리스트 위치값으로 저장

        외부 참조 파일
        fav.txt : 즐겨찾기에 대한 정보 / 위치값("경기 안양시")으로 한줄씩 저장.

        기존 알람도 저장하였으나 제외.

 */


package anyang_sw.micro;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.support.annotation.Nullable;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class TestService extends Service {
    @Nullable
    @Override
    public IBinder onBind(Intent intent){
        return null;
    }
    @Override
    public void onTaskRemoved(Intent rootIntent){

            ArrayList<String> listfav = new ArrayList<String>();
            listfav = Favorit.staticItems;

            // ArrayList<String> listalarm = MainActivity.alarmTime;

            File favfile = new File(getFilesDir()+"fav.txt") ;
          // File alarmfile = new File(getFilesDir()+"alarm.txt") ;

            FileWriter favfw = null ;
            BufferedWriter favbufwr = null ;
           // FileWriter alarmfw = null ;
           // BufferedWriter alarmbufwr = null ;


            try {
                // open file.
                favfw = new FileWriter(favfile) ;
                favbufwr = new BufferedWriter(favfw) ;
              //  alarmfw = new FileWriter(alarmfile) ;
               // alarmbufwr = new BufferedWriter(alarmfw) ;


                // write data to the file.
                for(int i =0; i<listfav.size();i++) {
                    favbufwr.write(listfav.get(i));
                    favbufwr.write("\n");
                }

              //  for(int i =0; i<listalarm.size();i++) {
             //       alarmbufwr.write(listalarm.get(i)+"\n");
             //   }

            } catch (Exception e) {
                e.printStackTrace() ;
            }

            // close file.
            try {
                if (favbufwr != null)
                   favbufwr.close() ;

                if (favfw != null)
                    favfw.close() ;

              //  if (alarmbufwr != null)
              //      alarmbufwr.close() ;

              //  if (alarmfw != null)
                //    alarmfw.close() ;
            } catch (Exception e) {
                e.printStackTrace();
            }




         stopSelf();
    }
}
