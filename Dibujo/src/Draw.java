import java.awt.*;
import javax.swing.JFrame;

public class Draw extends JFrame{
    public Draw(){
        setTitle("Dibujo");
        setSize(1000,1000);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public void paint (Graphics g){
        Graphics2D g2 = (Graphics2D) g;
        // ========== Pegar Aqui ==========

    }

    public static void main(String[] args){
        Draw draw = new Draw();
    }
}
