/*
/////////////////////////////////////////////////////////////////////////////////////////////////////
    미세먼지 알림 프로그램
    메인 부분
    작성자 : 조상호, 이채원, 유성근, 김성표

    작성일 : 2018.12.07

    구조 ; 이 프로그램은 다음과 같은 클래스로 구성되어있음
        OpenApi : 미세먼지 정보에 대한 클래스로 airkorea와 연계됨.
                메소드
                launching : 주소 입력에 따른 미세먼지 값을 returns에 저장하도록 하는 메소드
                strnul : 문자가 null이거나 빈문자열일 경우 구분해주는 메소드
                subStringGps : 주소의 [ 시/도 ] [ 구 / 면 / 시] 를 구분해주는 메소드
                getDates : 갱신시간(airkorea자체)을 반환해주는 메소드
                city_info : 시단위( 소속 지역구들 포함) 미세먼지 값을 받아서 반환해주는 메소드
                borough_info : 시/도 소속 지역구의 데이터를 구분해주는 메소드
                getString : 미세먼지 값을 출력해주는 메소드( 단위테스트시 사용)
                reset : 위치변경 / 즐겨찾기등으로 찾고자하는 지역이 변경될 경우 호출되는 메소드
                getPM10 : 미세먼지 데이터를 얻는 메소드
                getDate : 미세먼지 갱신시간(airkorea기준)을 출력용 string으로 반환 해주는 메소드
                getLocation : 출력된 지역의 위치를 반환해주는 메소드


        MainActivity : 종합적인 메인 컨트롤 클래스
                메소드
                initAlarm : 처음 실행될시 파일입출력으로 알람시간을 불러오는 메소드
                onCreate : 해당 액티비티가 표시될시 실행되는 메소드
                startService : 미세먼지 값을 불러오는 메소드
                Alarm :  알람설정하는 메소드
                onRequestPermissionsResult : GPS사용하는 퍼미션이 설정안되있을시 사용 요청하는 메소드
                setBackGroundColors : 미세먼지 값에 따른 배경색 및 미세먼지 농도상태등을 설정해주는 메소드
                startLocationService :  GPS 서비스를 시작하는 메소드
                searchLocation : 현재 지역의 GPS값에 따른 실제주소를 반환하는 메소드

                클래스
                GPSListener : GPS의 위치변경등 처리하는 클래스
                AlarmHATT : 알림에 대한 클래스 알림설정을 담당
                SlidingPageAnimationListener : 메뉴 실행/ 축소등을 담당하는 클래스
                DialogFlagment : 위치탐색 메뉴의 리스트 및 클릭 이벤트 처리하는 클래스

    공유 변수
        MainActivity 클래스
            DialogFlagment df : String selelct 만 바뀌며, 값의 범위는 "" 또는 위치값("경기 안양시") 등이다.
            static String fav :  즐겨찾기시 위치값("경기 안양시") 등 설정
            int sPM10 : 알람에 전달하는 미세먼지 값 저장. 범위 : 0 ~ 500
            String sLocation : 알림에 전달하는 지역 값 : 범위 "" 또는 위치값
            String sDate : 알림에 전달하는 시간에 대한 값 : 범위 "" 또는 "(시):(분)"
            ArrayList<String> alarmTime : 알람에 대한 시간정보 저장.

        (시) : 0~23 의 수
        (분) : 0~59 사이의 수
        위치값 : interface geoName에 저장되어있는 Fullgeo중 한가지 값

        외부 참조 파일
            alarm.txt : 알람시간에 대한 정보 / 한 줄당 "0:0" 식으로 저장

/////////////////////////////////////////////////////////////////////////////////////////////////////
 */


package anyang_sw.micro;


import android.app.AlarmManager;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.Notification;
import android.app.NotificationManager;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.FragmentManager;
import android.app.PendingIntent;
import android.content.*;
import android.content.Context;
import android.content.pm.PackageManager;
import android.support.constraint.ConstraintLayout;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.os.StrictMode;
import android.util.Log;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import java.io.*;
import java.net.*;
import java.util.*;
import android.location.*;


interface  geoName{
    /*
        지역구 저장하는 인터페이스
        순서대로 서울, 부산, 대구, 인천, 광주, 대전, 울산, 경기, 강원, 충북, 충남, 전북, 전남, 경북, 경남, 제주,세종

     */

    String[][] geo= {
            {"강남구", "강동구", "강북구", "강서구", "관악구", "광진구", "구로구", "금천구", "노원구", "도봉구", "동대문구", "동작구", "마포구", "서대문구", "서초구", "성동구", "송파구", "양천구", "영등포구", "용산구", "은평구", "종로구", "중구", "중량구" },//서울
            {"강서구", "금정구", "기장군", "남구", "동구", "동래구", "부산진구", "북구", "사상구", "사하구", "서구", "수영구", "연제구", "영도구", "중구", "해운대구" },//부산
            {"남구","달서구","달성군","동구","북구","서구","수성구","중구"},//대구
            {"강화군","계양구","남구","남동구","동구","부평구","서구","연수구","중구"},//인천
            {"광산구","남구","동구","북구","서구"},//광주
            {"대덕구","동구","서구","유성구","중구"},//대전
            {"남구","동구","북구","울주군","중구"},//울산
            {"가평군","고양시","과천시","광명시","광주시","구리시","군포시","김포시","남양주시","동두천시","부천시","성남시","수원시","시흥시","안산시","안성시","안양시","양주시","양평군","여주군","연천군","오산시","용인시","의왕시","의정부시","이천시","파주시","평택시","포천시","하남시","화성시"},//경기
            {"강릉시","동해시","삼척시","원주시","춘천시","평창군"},//강원
            {"단양군","영동군","옥천군","제천시","진천군","청주시","충주시"},//충북
            {"공주시","금산군","논산시","당진군","보령시","부여군","서산시","서천군","아산시","예산군","천안시","청양군","태안군","홍성군"},//충남
            {"고창군","군산시","김제시","남원시","무주군","부안군","순창군","완주군","익산시","임실군","전주시","정읍시","진안군"},//전북
            {"광양시","나주시","담양군","목포시","순천시","여수시","영광군","장성군","해남군"},//전남
            {"경산시","경주시","구미시","김천시","상주시","영주시","칠곡군","포항시"},//경북
            {"거제시","김해시","밀양시","사천시","양산시","진주시","창원시","통영시","하동군"},//경남
            {"서귀포시","제주시"},//제주
            {"세종시"}//세종
    };

    String[] Fullgeo ={
            "강원 원주시",
            "강원 삼척시",
            "강원 춘천시",
            "강원 동해시",
            "강원 평창군",
            "강원 강릉시",

            "경기 동두천시",
            "경기 수원시",
            "경기 의왕시",
            "경기 부천시",
            "경기 시흥시",
            "경기 여주군",
            "경기 양주시",
            "경기 안산시",
            "경기 파주시",
            "경기 과천시",
            "경기 가평군",
            "경기 오산시",
            "경기 하남시",
            "경기 군포시",
            "경기 의정부시",
            "경기 김포시",
            "경기 연천군",
            "경기 남양주시",
            "경기 용인시",
            "경기 성남시",
            "경기 이천시",
            "경기 광주시",
            "경기 광명시",
            "경기 안양시",
            "경기 안성시",
            "경기 평택시",
            "경기 고양시",
            "경기 포천시",
            "경기 구리시",
            "경기 양평군",
            "경기 화성시",

            "경남 진주시",
            "경남 사천시",
            "경남 창원시",
            "경남 양산시",
            "경남 김해시",
            "경남 거제시",
            "경남 하동군",
            "경남 통영시",
            "경남 밀양시",

            "경북 구미시",
            "경북 경주시",
            "경북 칠곡군",
            "경북 김천시",
            "경북 경산시",
            "경북 영주시",
            "경북 포항시",
            "경북 상주시",

            "광주 서구",
            "광주 북구",
            "광주 동구",
            "광주 광산구",
            "광주 남구",

            "대구 서구",
            "대구 북구",
            "대구 동구",
            "대구 달성군",
            "대구 수성구",
            "대구 남구",
            "대구 달서구",
            "대구 중구",

            "대전 서구",
            "대전 유성구",
            "대전 동구",
            "대전 대덕구",
            "대전 중구",

            "부산 사하구",
            "부산 서구",
            "부산 동래구",
            "부산 동구",
            "부산 해운대구",
            "부산 중구",
            "부산 북구",
            "부산 강서구",
            "부산 영도구",
            "부산 기장군",
            "부산 금정구",
            "부산 부산진구",
            "부산 사상구",
            "부산 수영구",
            "부산 남구",
            "부산 연제구",

            "서울 서대문구",
            "서울 동작구",
            "서울 마포구",
            "서울 중구",
            "서울 성동구",
            "서울 광진구",
            "서울 중랑구",
            "서울 도봉구",
            "서울 은평구",
            "서울 양천구",
            "서울 강북구",
            "서울 동대문구",
            "서울 노원구",
            "서울 송파구",
            "서울 종로구",
            "서울 강서구",
            "서울 구로구",
            "서울 서초구",
            "서울 영등포구",
            "서울 강남구",
            "서울 강동구",
            "서울 성북구",
            "서울 관악구",
            "서울 용산구",
            "서울 금천구",

            "세종 세종시",

            "인천 서구",
            "인천 동구",
            "인천 부평구",
            "인천 강화군",
            "인천 남구",
            "인천 중구",
            "인천 계양구",
            "인천 연수구",
            "인천 남동구",

            "울산 울주군",
            "울산 북구",
            "울산 동구",
            "울산 남구",
            "울산 중구",

            "전남 영암군",
            "전남 여수시",
            "전남 장성군",
            "전남 담양군",
            "전남 목포시",
            "전남 영광군",
            "전남 나주시",
            "전남 순천시",
            "전남 해남군",
            "전남 광양시",

            "전북 임실군",
            "전북 무주군",
            "전북 전주시",
            "전북 익산시",
            "전북 남원시",
            "전북 순창군",
            "전북 군산시",
            "전북 진안군",
            "전북 고창군",
            "전북 부안군",
            "전북 정읍시",
            "전북 김제시",
            "전북 완주군",

            "제주 서귀포시",
            "제주 제주시",

            "충남 공주시",
            "충남 서천군",
            "충남 아산시",
            "충남 당진군",
            "충남 홍성군",
            "충남 서산시",
            "충남 보령시",
            "충남 청양군",
            "충남 예산군",
            "충남 태안군",
            "충남 논산시",
            "충남 금산군",
            "충남 천안시",
            "충남 부여군",

            "충북 제천시",
            "충북 단양군",
            "충북 영동군",
            "충북 진천군",
            "충북 청주시",
            "충북 옥천군",
            "충북 충주시",
    };
}


class OpenApi {

    private static final String serviceKey = "zGycX1SC%2B8KiLfnwFBCCy0IXosRMQ90iWo6MTQNBTUtR5as362SMJOUzu%2BWtx%2B9YX1eVidcrGLfEH3Lc3B16MQ%3D%3D";
    private StringBuilder returns = new StringBuilder();
    private Date date;
    private String[] city;
    private int[] pmValue;



    public OpenApi() {
        city = new String[2];
        city[0] = "경기";
        city[1] = "안양시";
        pmValue = new int[2];
        pmValue[0] = -1;
        pmValue[1] = -1;
    }

    public void launching(String s, int check){
        //gps -> 위치 구분 -> 불러오기
        city[0] = "경기";
        city[1] = "안양시";
        if(!(s.equals("error")||s.equals(""))&&check == 0) {
            //구분필요
            /*
            city[0] = "서울";
            city[1] = "구로구";
            returns.append(s);
            */

            city = subStringGps(s);
        }
        else if(!(s.equals("error")||s.equals(""))&&check == 1){
            String[] temp = s.split(" ");
            city[0] = temp[0];
            city[1] = temp[1];
        }
        date = new Date();
        String cityInfomation = city_info(city[0]);
        date = getDates(cityInfomation);
        // 문자열 자르기
        int[] pm;

        pm = borough_info(cityInfomation, city[1]);
        returns.append(city[1] + "\n현재 미세먼지 : "+pm[0] + "\n초 미세먼지 : "+pm[1]+"\n" );
        // returns.append(city[1] + "/"+pm[0] + "/"+pm[1]+"/" );
        // returns.append(s);
        returns.append(date.toString());
    }

    private boolean strnul(String s){
        if(s.equals("NULL")||s.equals("")||s.equals("Error"))
            return true;
        return false;
    }

    private String[] subStringGps(String gps){

        String[] restr = new String[2];
        String[] str = gps.split(" ");
        switch (str[1]){
            case "서울특별시":
                restr[0] = "서울";
                break;
            case "부산광역시":
                restr[0] = "부산";
                break;
            case "대구광역시":
                restr[0] = "대구";
                break;
            case "인천광역시":
                restr[0] = "인천";
                break;
            case "광주광역시":
                restr[0] = "광주";
                break;
            case "대전광역시":
                restr[0] = "대전";
                break;
            case "울산광역시":
                restr[0] = "울산";
                break;
            case "경기도":
                restr[0] = "경기";
                break;
            case "강원도":
                restr[0] = "강원";
                break;
            case "충청북도":
                restr[0] = "충북";
                break;
            case "충청남도":
                restr[0] = "충남";
                break;
            case "전라북도":
                restr[0] = "전북";
                break;
            case "전라남도":
                restr[0] = "전남";
                break;
            case "경상북도":
                restr[0] = "경북";
                break;
            case "경상남도":
                restr[0] = "경남";
                break;
            case "제주특별자치도":
                restr[0] = "제주";
                break;
            case "세종특별자치시":
                restr[0] = "세종";
                break;
        }
        restr[1] = str[2];
        return restr;
    }

    private Date getDates(String cityInfo){

        if(strnul(cityInfo))
            return new Date(0,0,0,0,0,0);

        Date newDate = new Date();
        String[] dateStringArray = cityInfo.split("<dataTime>");
        try {
            String dateString = dateStringArray[1].substring(0, dateStringArray[1].indexOf("</dataTime>"));
            String[] dateParse = dateString.split("-");
            String[] dayParse = dateParse[2].split(" ");
            String[] timeParse = dayParse[1].split(":");

            newDate.setYear(Integer.parseInt(dateParse[0]) - 1900);
            newDate.setMonth(Integer.parseInt(dateParse[1]) - 1);
            newDate.setDate(Integer.parseInt(dayParse[0]));
            newDate.setHours(Integer.parseInt(timeParse[0]));
            newDate.setMinutes(Integer.parseInt(timeParse[1]));
            newDate.setSeconds(0);

            return newDate;
        }
        catch (ArrayIndexOutOfBoundsException aioobe){
            aioobe.printStackTrace();
            return new Date(0,0,0,0,0,0);
        }

    }

    private String city_info(String city){
        StringBuilder returnString = new StringBuilder("");
        BufferedReader rd;
        HttpURLConnection conn=null;
        try {
            StringBuilder urlBuilder = new StringBuilder("http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getCtprvnMesureSidoLIst"); /*URL*/

            urlBuilder.append("?" + URLEncoder.encode("ServiceKey", "UTF-8") + "=" + serviceKey); /*Service Key*/
            urlBuilder.append("&" + URLEncoder.encode("numOfRows", "UTF-8") + "=" + URLEncoder.encode("100", "UTF-8")); /*한 페이지 결과 수*/
            urlBuilder.append("&" + URLEncoder.encode("pageNo", "UTF-8") + "=" + URLEncoder.encode("1", "UTF-8")); /*페이지 번호*/
            urlBuilder.append("&" + URLEncoder.encode("sidoName", "UTF-8") + "=" + URLEncoder.encode(city, "UTF-8")); /*시도 이름 (서울, 부산, 대구, 인천, 광주, 대전, 울산, 경기, 강원, 충북, 충남, 전북, 전남, 경북, 경남, 제주, 세종)*/
            urlBuilder.append("&" + URLEncoder.encode("searchCondition", "UTF-8") + "=" + URLEncoder.encode("HOUR", "UTF-8")); /*요청 데이터기간 (시간 : HOUR, 하루 : DAILY)*/

            URL url = new URL(urlBuilder.toString());
            conn = (HttpURLConnection) url.openConnection();
            conn.setRequestMethod("GET");
            conn.setRequestProperty("Content-type", "application/json");
            int ResponseCode = conn.getResponseCode();
            returnString.append("Response code: " + ResponseCode + "\n");

            if (ResponseCode >= 200 && ResponseCode <= 300) {
                rd = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            } else {
                rd = new BufferedReader(new InputStreamReader(conn.getErrorStream()));
            }
            StringBuilder sb = new StringBuilder();
            String line;
            while ((line = rd.readLine()) != null) {
                sb.append(line);
            }
            rd.close();
            conn.disconnect();
            returnString.append(sb.toString());

            return returnString.toString();
        }
        catch (IOException e){
            if(conn!=null)
                conn.disconnect();
            return "Error";
        }
    }

    private int[] borough_info(String city_infos , String location){

        if(strnul(city_infos))
            return pmValue;

        String[] borough = city_infos.split("<cityName>");
        for(int i = 1; i < borough.length;i++){
            if(borough[i].substring(0, borough[i].indexOf("</cityName>")).equals(location)){
                String temp = borough[i].substring(borough[i].indexOf("<pm10Value>")+"<pm25Value>".length(),borough[i].indexOf("</pm10Value"));
                    if(temp.equals("-"))
                        pmValue[0] = 0;
                    else
                        pmValue[0] = Integer.parseInt(temp);

                    temp = borough[i].substring(borough[i].indexOf("<pm25Value>")+"<pm25Value>".length(),borough[i].indexOf("</pm25Value"));
                    if(temp.equals("-"))
                        pmValue[1] = 0;
                    else
                        pmValue[1] = Integer.parseInt(temp);
                return pmValue;
            }
        }
        return pmValue;
    }

    public String getString(){
        return returns.toString();
    }

    public void reset(String s, int check){
        Date newDate = new Date();
        Date af = (Date) date.clone();
        af.setHours(date.getHours()+1);
        String temp = city[0] + " "+city[1];
        if(newDate.after(af) || !(s.equals(temp))){
            returns.delete(0, returns.length());
            pmValue = new int[2];
            pmValue[0] = -1;
            pmValue[1] = -1;

            launching(s,check);
        }

    }

    public int getPM10(){
        return pmValue[0];
    }

    public String getDate(){
        String s = date.getHours() +"시"+ date.getMinutes()+"분";
        return s;
    }

    public String getLocation(){
        String s = city[0] + " " +city[1];
        return s;
    }

}

public class MainActivity extends AppCompatActivity     {

    private static final int PERMISSIONS_REQUEST_ACCESS_FINE_LOCATION = 1;

    private double[] locationDouble;

    private OpenApi oa;
    private Geocoder gc;

    private TextView locate;
    private TextView PM10;
    private TextView havior;
    private ImageView img;
    private ImageView refresh;
    private ImageView menubutton;
    private LinearLayout menuLayout;
    private ConstraintLayout mainbg;

    private  boolean menuOn=false;
    private Animation openTransLtoR;
    private Animation closeTransRtoL;


    private AlarmHATT[] alarm;

    static int sPM10;
    static String sLocation;
    static String sDate;
    public static int getsPM10(){
        return sPM10;
    }
    public static String getsLocation(){return sLocation;}
    public static String getsDate(){return sDate;}



    public static String fav;

    private Button addLocation;
    private Button alarmSet;
    private Button favorit;

    public static DialogFlagment df;

    public static ArrayList<String> alarmTime;
    private int[][] alarms;

    private boolean state = true;

    private void initAlarm(){
        alarms = new int[5][2];

        alarmTime = new ArrayList<String>();

        File file = new File(getFilesDir()+"/alarm.txt") ;

        if(!file .exists()){
            FileWriter fw=null;
            try {
                fw = new FileWriter(file);
                fw.write("7:00");
                fw.write("\n");
                fw.write("11:00");
                fw.write("\n");
                fw.write("17:00");
                fw.write("\n");
            }
            catch(Exception e){
                e.printStackTrace();
            }
            try{
                if(fw!=null)
                    fw.close();
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }

        FileReader fr= null;
        BufferedReader br =null;
        String data ;
        String str ="";

        try {
            // open file.
            fr = new FileReader(file) ;
            br = new BufferedReader(fr);

            // read file.
            while ((data = br.readLine()) != null) {
                // TODO : use data
                str += data +"/" ;
            }

        } catch (Exception e) {
            e.printStackTrace() ;
        }

        try{
            if(br !=null)
                br.close();
            if(fr!=null)
                fr.close() ;
        }
        catch(Exception e){
            e.printStackTrace();
        }

        if(!(str.equals(""))) {
            String[] liststr = str.split("/");
            String[] temp;
            for (int i = 0; i < liststr.length; i++) {
                temp = liststr[i].split(":");
                alarmTime.add(liststr[i]);
                alarms[i][0] = Integer.parseInt(temp[0]);
                alarms[i][1] = Integer.parseInt(temp[1]);
            }
        }
        else{
            alarmTime.add("7:00");
            alarmTime.add("11:00");
            alarmTime.add("17:00");

            for (int i = 0; i < alarmTime.size(); i++) {
                alarms[i][0] = Integer.parseInt(alarmTime.get(i).split(":")[0]);
                alarms[i][1] = Integer.parseInt(alarmTime.get(i).split(":")[1]);
            }
        }

    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        StrictMode.enableDefaults();

        locationDouble = new double[2];
        locate = findViewById(R.id.textV);
        PM10 = findViewById(R.id.pm10);
        havior = findViewById(R.id.havior);
        img = findViewById(R.id.iView);

        gc = new Geocoder(this,Locale.KOREAN);
        refresh = findViewById(R.id.refresh);

        menuLayout = findViewById(R.id.menuLayout);
        openTransLtoR = AnimationUtils.loadAnimation(this,R.anim.open);
        closeTransRtoL = AnimationUtils.loadAnimation(this,R.anim.close);

        menubutton = findViewById(R.id.menubutton);
        mainbg = findViewById(R.id.mainbg);

        addLocation = findViewById(R.id.addLocation);
        alarmSet= findViewById(R.id.setAlarm);
        favorit= findViewById(R.id.Favorite);

        sPM10 = 0;
        sLocation = new String();
        sDate = new String();

        fav = new String();
        for(int i = 0; i<2;i++){
            locationDouble[i] = 0.0;
        }
        oa = new OpenApi() ;

        if(ContextCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{android.Manifest.permission.ACCESS_FINE_LOCATION}, PERMISSIONS_REQUEST_ACCESS_FINE_LOCATION);
        }

        alarm = new AlarmHATT[5];

        for(int i = 0; i<5;i++) {
            alarm[i] = new AlarmHATT(getApplicationContext(), i);
        }
        initAlarm();

        startService();
        Alarm();

        sPM10 = oa.getPM10();
        sLocation = oa.getLocation();
        sDate = oa.getDate();

        //alarm[0].setAlarm(5,41);
        SlidingPageAnimationListener animListener = new SlidingPageAnimationListener();
        openTransLtoR.setAnimationListener(animListener);
        closeTransRtoL.setAnimationListener(animListener);


        menubutton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(v.getId() == R.id.menubutton ){
                    if(!menuOn){
                        menuLayout.setVisibility(View.VISIBLE);
                        menuLayout.startAnimation(openTransLtoR);
                    }
                }
            }
        });

        mainbg.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(v.getId() == R.id.mainbg ){
                    if(menuOn){
                        menuLayout.startAnimation(closeTransRtoL);
                    }
                }
            }
        });

        refresh.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(v.getId() == R.id.refresh ){

                    state = true;
                    oa.reset(searchLocation(),0);
                    locate.setText(oa.getLocation()+ "\n갱신시간 : "+oa.getDate());
                    setBackGroundColors(oa.getPM10());
                }
            }
        });
        df = new DialogFlagment();
        addLocation.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(v.getId() == R.id.addLocation ) {
                    state = false;
                    FragmentManager fm = getSupportFragmentManager();

                    df.show(fm,"");
                    menuLayout.startAnimation(closeTransRtoL);
                }
            }
        });

        alarmSet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (v.getId() == R.id.setAlarm) {
                    Intent i = new Intent(MainActivity.this,SetAlarm.class);


                    startActivity(i);
                    menuLayout.startAnimation(closeTransRtoL);
                }
            }
        });

        favorit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (v.getId() == R.id.Favorite) {
                    state = false;
                    Intent i = new Intent(getApplicationContext(),Favorit.class);
                    startActivity(i);
                    menuLayout.startAnimation(closeTransRtoL);
                }
            }
        });
    }

    private void startService(){
        startLocationService();
        oa.launching(searchLocation(),0);
        locate.setText(oa.getLocation()+ "\n갱신시간 : "+oa.getDate());
        //status1.setText(oa.getString());
        setBackGroundColors(oa.getPM10());

        sPM10 = oa.getPM10();
        sLocation = oa.getLocation();
        sDate = oa.getDate();


    }

    private void Alarm(){
        for(int i = 0; i <alarmTime.size();i++){
            alarms[i][0] = Integer.parseInt(alarmTime.get(i).split(":")[0]);
            alarms[i][1] = Integer.parseInt(alarmTime.get(i).split(":")[1]);
            if(alarms[i][0] == -1){
                continue;
            }
            else {
                alarm[i].setAlarm(alarms[i][0], alarms[i][1]);
            }
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        switch (requestCode){
            case PERMISSIONS_REQUEST_ACCESS_FINE_LOCATION:
            {
                if (!(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED)){
                    startLocationService();
                }
                return;
            }
        }
    }

    private void setBackGroundColors(int pm){
        ImageView bg = findViewById(R.id.background);
        String s = "현재농도 :  " + pm + " / ";
        String content = "";
        if(pm<0){
            bg.setImageResource(R.color.backgrounds);
            img.setImageResource(0);
            s = "측정이 잘못되었습니다.";
            content = "조속히 조치하겠습니다. 죄송합니다.";
        }
        else if(pm<=15) {
            bg.setImageResource(R.color.Good);
            img.setImageResource(R.drawable.good);
            s = s+"좋음";
            content = "미세먼지 걱정 없는 하루!";
        }
        else if(pm<=35) {
            bg.setImageResource(R.color.Fine);
            img.setImageResource(R.drawable.fine);
            s = s+"보통";
            content = "실외활동 시 특별히 행동에 제약을 받을 필요는 없지만 몸 상태에 따라 유의하여 활동하시기 바랍니다.";
        }
        else if(pm<=75) {
            bg.setImageResource(R.color.Warning);
            img.setImageResource(R.drawable.warning);
            s = s+"나쁨";
            content = "마스크 착용 권고\n 어린이와 노인, 호흡기 질환자 등은 외출을 자제,\n 장시간 또는 무리한 실외활동 제한하며 \n 특히 눈이 아픈 증상이 있거나 기침이나 목의 통증으로 불편한 사람은 실외활동을 피해야 합니다.";
        }
        else {
            bg.setImageResource(R.color.Bad);
            img.setImageResource(R.drawable.bad);
            s = s+"매우나쁨";
            content = "마스크 착용 권고\n 어린이와 노인, 호흡기 질환자 등은 외출을 자제\n 장시간 또는 무리한 실외활동 제한 하며\n 목의 통증과 기침 등의 증상이 있는 사람은 실외활동을 피해야 합니다.";
        }

        PM10.setText(s);
        havior.setText(content);

        sPM10 = oa.getPM10();
        sLocation = oa.getLocation();
        sDate = oa.getDate();
        /*

    <color name="Bad">#af0000</color>175
    <color name="Warning">#999900</color>153 153
    <color name="Good">#44F000</color>68 240
    <color name="Fine">#00FFff</color>
         */
    }

    private void startLocationService() {


        LocationManager manager = (LocationManager) getSystemService(Context.LOCATION_SERVICE);

        GPSListener gpsListener = new GPSListener();
        long minTime = 10000;
        float minDistance = 0;

        try {
            manager.requestLocationUpdates(
                    LocationManager.GPS_PROVIDER,
                    minTime,
                    minDistance,
                    gpsListener);

            manager.requestLocationUpdates(
                    LocationManager.NETWORK_PROVIDER,
                    minTime,
                    minDistance,
                    gpsListener);

            Location lastLocation = manager.getLastKnownLocation(LocationManager.GPS_PROVIDER);
            if (lastLocation != null) {
                locationDouble[0] = lastLocation.getLatitude();
                locationDouble[1] = lastLocation.getLongitude();
            }
        } catch(SecurityException ex) {
            ex.printStackTrace();
        }
        catch(NullPointerException e){
            Log.d("NULL",e.getMessage());
        }


    }

    private class GPSListener implements LocationListener {
        public void onLocationChanged(Location location) {
            locationDouble[0] = location.getLatitude();
            locationDouble[1] = location.getLongitude();
            String search = searchLocation();
            if(state && !(search.equals(oa.getLocation()))) {
                oa.reset(searchLocation(),0);
                locate.setText(oa.getLocation() + "\n갱신시간 : " + oa.getDate());
                //status1.setText(oa.getString());
                setBackGroundColors(oa.getPM10());
            }
            else if(!df.getSelect().equals("")){
                oa.reset(df.getSelect(),1);
                locate.setText(oa.getLocation() + "\n갱신시간 : " + oa.getDate());
                //status1.setText(oa.getString());
                setBackGroundColors(oa.getPM10());
            }
            else if(!fav.equals("")){
                oa.reset(fav,1);
                locate.setText(oa.getLocation() + "\n갱신시간 : " + oa.getDate());
                //status1.setText(oa.getString());
                setBackGroundColors(oa.getPM10());
            }
            Alarm();
        }

        public void onProviderDisabled(String provider) {
        }

        public void onProviderEnabled(String provider) {
        }

        public void onStatusChanged(String provider, int status, Bundle extras) {
        }

    }

    private String searchLocation() {
        List<Address> addressList = null;
        StringBuilder contentsText= new StringBuilder();
        try {

            addressList = gc.getFromLocation(locationDouble[0], locationDouble[1], 1);

            //io Exception 발생

            if (addressList != null) {
                for (int i = 0; i < addressList.size(); i++) {
                    Address outAddr = addressList.get(i);
                    int addrCount = outAddr.getMaxAddressLineIndex() + 1;
                    StringBuffer outAddrStr = new StringBuffer();
                    for (int k = 0; k < addrCount; k++) {
                        outAddrStr.append(outAddr.getAddressLine(k));
                    }
                    contentsText.append(outAddrStr.toString());
                }
            }
            return contentsText.toString();

        } catch(IOException ex) {
            return "error";
        }
    }

    private class AlarmHATT {
        int id;
        private Context context;
        Calendar calendar;
        public AlarmHATT(Context context,int id) {
            this.context = context;
            this.id = id;
        }

        public void setAlarm(int hour, int min) {
            AlarmManager am = (AlarmManager)context.getSystemService(Context.ALARM_SERVICE);

            Intent intent = new Intent(MainActivity.this, BroadcastD.class);
            intent.putExtra(BroadcastD.ID,id);

            PendingIntent sender = PendingIntent.getBroadcast(MainActivity.this, 0, intent, 0);

            calendar = Calendar.getInstance();
            //알람시간 calendar에 set해주기


            calendar.set(calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH), calendar.get(Calendar.DATE), hour, min, 0);

            //알람 예약
            am.set(AlarmManager.RTC_WAKEUP, calendar.getTimeInMillis(), sender);
        }
    }

    private class SlidingPageAnimationListener implements Animation.AnimationListener{
        @Override
        public void onAnimationRepeat(Animation animation) {

        }

        @Override
        public void onAnimationStart(Animation animation) {

        }

        public void onAnimationEnd(Animation ani){
            if(menuOn){
                menuLayout.setVisibility(View.INVISIBLE);
                menuOn=false;
            }
            else{

                menuOn=true;
            }
        }
    }

    public static class DialogFlagment extends DialogFragment implements  geoName {
        String select;
        public DialogFlagment(){
            select="";
        }
        @Override
        public Dialog onCreateDialog(Bundle savedInstanceState) {
            AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
            builder.setTitle(R.string.locationSearch)
                    .setItems(R.array.locallist, new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int which) {
                            // The 'which' argument contains the index position
                            // of the selected item
                           select =  Fullgeo[which];
                        }
                    });
            return builder.create();
        }
        public String getSelect(){
            return  select;
        }

        public void setSelect(String select) {
            this.select = select;
        }
    }



}
