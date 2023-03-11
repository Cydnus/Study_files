import processing.serial.*;

Serial port;
String mystr = null;
int angle, distance;

void setup()
{
    size(1200,700);
    background(0);
    port = new Serial(this, Serial.list()[0], 9600);
}


void draw()
{
    noStroke();
    fill(0,7);
    rect(0,0,width,height);
    DrawRader();
     DrawLine();
     DrawObject();
    
}

void serialEvent(Serial port)
{
    try
    {
        mystr = port.readStringUntil('.');    
        if( mystr !=null)
        {
            
        String[] list = split(mystr,',');
        angle = int(trim(list[0]));
        double temp = Long.parseLong(list[1].replace(".","")) /2 *0.034;
        distance = (int)temp;
        print("Angle : " + angle);
        println("\tDistance : "+ distance); 
        } 
    }
    catch(Exception e)
    {}
        
}

void DrawRader()
{
    pushMatrix();
    translate(width/2,height);
    noFill();
    strokeWeight(2);
    stroke(980,245,31);
    arc(0,0,width,width,PI,TWO_PI);
    arc(0,0,width*2/3,width*2/3,PI,TWO_PI);
    arc(0,0,width/3,width/3,PI,TWO_PI);
    line(0,0,width/2 * cos(radians(30)), -width/2 * sin(radians(30)));
    line(0,0,width/2 * cos(radians(60)), -width/2 * sin(radians(60)));
    line(0,0,width/2 * cos(radians(90)), -width/2 * sin(radians(90)));
    line(0,0,width/2 * cos(radians(120)), -width/2 * sin(radians(120)));
    line(0,0,width/2 * cos(radians(150)), -width/2 * sin(radians(150)));
    
    textSize(15);
    fill(98,245,31);
    textAlign(RIGHT);
    text("10cm",width/6,0);
    text("20cm",width*2/6,0);
    text("30cm",width*3/6,0);
    
    
    popMatrix();
}

void DrawLine()
{
     pushMatrix();
    translate(width/2,height);
    strokeWeight(4);
    stroke(98,245,31);
    line(0,0,width/2*cos(radians(angle)), -width/2*sin(radians(angle)));
    
    popMatrix();
}
void DrawObject()
{
     pushMatrix();
     
     
    translate(width/2,height);
    strokeWeight(4);
    stroke(255,0,0);
    float d = (width/2.0/30.0)*(float)distance;
    if(d<width/2)
    {
    line(d*cos(radians(angle)),-d*sin(radians(angle)),width/2*cos(radians(angle)), -width/2*sin(radians(angle)));
    
    }
    popMatrix();
}
    
