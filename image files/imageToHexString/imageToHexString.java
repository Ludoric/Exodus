
import ecs100.*;
import java.util.*;
import java.io.*;
import java.awt.Color;
import java.awt.image.*;
import javax.imageio.ImageIO;

/** <description of class imageToHexString>
*/
public class imageToHexString{
  public BufferedImage image;
  // public double cuttoff1 = 63;
  // public double cuttoff2 = 127;
  // public double cuttoff3 = 191;
  public int mode = 0;

  /**
  * Construct a new imageToHexString object
  */
  public imageToHexString(){
    setupGUI();
  }

  /**
  * Setup the GUI
  */
  public void setupGUI(){
    UI.addButton("Load", this::load);
    UI.addButton("Save", this::save);
    UI.addButton("Toggle Colour Mode", this::toggleMode);
    // UI.addSlider("cuttoff ONE",0,255,63, this::slider1);
    // UI.addSlider("cuttoff TWO",0,255,127, this::slider2);
    // UI.addSlider("cuttoff THREE",0,255,191, this::slider3);
    UI.addButton("Quit", UI::quit);
    UI.setDivider(1.0);
    UI.println("TWO colour mode");
  }

  // public void slider1(double value){
  //   cuttoff1 = value;
  // }
  // public void slider2(double value){
  //   cuttoff2 = value;
  // }
  // public void slider3(double value){
  //   cuttoff3 = value;
  // }

  public void toggleMode(){
    mode = (mode+1)%3;
    switch(mode){
      case 0:
      UI.println("TWO colour mode");
      break;
      case 1:
      UI.println("FOUR colour mode");
      break;
      case 2:
      UI.println("16 colour mode");
      break;
    }
  }

  public void save(){

    switch(mode){
      case 0:
      save2colour();
      break;
      case 1:
      save4colour();
      break;
      case 2:
      save16colour();
      break;
    }
  }

  public void save16colour(){
    StringBuilder s = new StringBuilder();
    s.append("{");
    int width = image.getWidth();
    int height = image.getHeight();

    for (int row = 0; row < height; row++) {
      long hex = 0;
      int counter = 0;
      for (int col = 0; col < width; col++) {

        counter++;
        hex = (hex<<4);// or times 16

        Color c = new Color(image.getRGB(col,row));
        int grey = (int)(0L + c.getRed()+c.getGreen()+c.getBlue())/3;
        //UI.println(grey);
        hex = hex + ((~(int)(grey/256.0*16.0))&0x0F);// THE IMPORTANT LINE (note the ~ operator)
        // UI.print(String.format("%08x", hex) + " ");
        if(counter == 8){
          s.append(", 0x"+String.format("%08x", hex));
          counter = 0;
          hex = 0;
        }
      }
      // UI.println();
      if(counter != 0){
        s.append(", error");
      }
    }
    s.append(" }");
    s.deleteCharAt(s.indexOf(","));
    //out.println(s);
    UI.println(s);
  }

  public void save4colour(){
    StringBuilder s = new StringBuilder();
    s.append("{");
    int width = image.getWidth();
    int height = image.getHeight();

    for (int row = 0; row < height; row++) {
      int hex = 0;
      int counter = 0;
      for (int col = 0; col < width; col++) {

        counter++;
        hex = (hex << 2);

        Color c = new Color(image.getRGB(col,row));
        int grey = (c.getRed()+c.getGreen()+c.getBlue())/3;
        //UI.println(grey);
        if(grey<63){
          hex |= 0x3;
        }else if(grey<127){
          hex |= 0x2;
        }else if(grey<191){
          hex |= 0x1;
        }else{
          hex |= 0x0;
        }
        if(counter == 8){
          s.append(", 0x"+String.format("%02x", hex));
          counter = 0;
          hex = 0;
        }
      }
      if(counter != 0){
        s.append(", error");
      }
    }
    s.append(" }");
    s.deleteCharAt(s.indexOf(","));
    //out.println(s);
    UI.println(s);
  }


  public void save2colour(){
    //try {
    //PrintStream out = new PrintStream(new File(UIFileChooser.save()));
    StringBuilder s = new StringBuilder();
    s.append("{");
    int width = image.getWidth();
    int height = image.getHeight();

    for (int row = 0; row < height; row++) {
      int hex = 0;
      int counter = 0;
      for (int col = 0; col < width; col++) {

        counter++;
        hex = (hex << 1);
        Color c = new Color(image.getRGB(col,row));
        if((c.getRed()+c.getGreen()+c.getBlue())/3.0< 128){
          hex |= 1;
        }

        if(counter == 8){
          s.append(", 0x"+String.format("%02x", hex));
          counter = 0;
          hex = 0;
        }

      }
      if(counter != 0){
        s.append(", error");
      }
    }

    s.append(" }");
    s.deleteCharAt(s.indexOf(","));
    //out.println(s);
    UI.println(s);
    //out.close();
    //} catch (IOException e) {UI.println("Error: " + e);}
  }

  /** method to respond to the button */
  public void load(){

    try {
      image = ImageIO.read(new File(UIFileChooser.open()));
      save();
    } catch (IOException e) {UI.println("Error: " + e);}
  }

  public static void main(String[] arguments){
    new imageToHexString();
  }

}
