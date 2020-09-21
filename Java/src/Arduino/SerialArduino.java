package Arduino;

import java.io.PrintWriter;
import java.util.Scanner;
import com.fazecast.jSerialComm.*;

public class SerialArduino {
	public static float stochMultiply(float a, float b) {
		SerialPort ports[] = SerialPort.getCommPorts();
		for(SerialPort port : ports) {
			System.out.println(port);
		}
		SerialPort arduinoPort = ports[0];
		
		arduinoPort.setComPortTimeouts(SerialPort.TIMEOUT_SCANNER, 0, 0);
		
		if(arduinoPort.openPort()) {
			System.out.println("Success: Opened Arduino port.");
		} else {
			System.out.println("Failure: Couldn't open Arduino port.");
			return 0;
		}
		
		try{
			Thread.sleep(1000);
		}catch(Exception e) {
			System.out.println("Failure: Sleep failed.");
		}
		
		PrintWriter arduinoSend = new PrintWriter(arduinoPort.getOutputStream());
		
		arduinoSend.println(a);
		arduinoSend.flush();
		arduinoSend.println(b);
		arduinoSend.flush();
		
		System.out.println(">>All Printed");
		
		Scanner arduinoRead = new Scanner(arduinoPort.getInputStream());
		float ans = 0;
		String reply;
		while(!((reply=arduinoRead.nextLine()).equals("end"))){
			ans = Float.parseFloat(reply);
		}
		System.out.println(ans);
		arduinoRead.close();
		arduinoPort.closePort();
		System.out.println("Port closed!");
		
		return ans;
	}

	public static void main(String[] args) {
		stochMultiply(0.5f,0.4f);
	}

}
