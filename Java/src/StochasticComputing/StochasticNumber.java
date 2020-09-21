package StochasticComputing;

public class StochasticNumber {
	private int streamLength;
	private boolean[] bitStream;
	private double streamValue;
	private double targetValue;
	private boolean negative;
	
	public StochasticNumber(double number, int l) {
		if(number<0)negative = true;
		else negative = false;
		
		streamLength = l;
		targetValue = number;
		int countOnes = 0;
		
		bitStream = new boolean[l];
		for(int i = 0; i < l; i++) {
			if(Math.random() < Math.abs(number)) {
				bitStream[i] = true;
				countOnes++;
			} else {
				bitStream[i] = false;
			}
		}
		
		streamValue = countOnes/(double)streamLength;
		streamValue = (negative) ? ((-1)*streamValue) : streamValue;
	}
	
	public StochasticNumber(boolean[] stream, boolean neg) {
		negative = neg;
		bitStream = stream;
		streamLength = bitStream.length;
		
		int countOnes = 0;
		for(int i = 0; i < streamLength; i++) {
			if (bitStream[i]) {
				countOnes++;
			}
		}
		
		streamValue = countOnes/(double)streamLength;
		streamValue = (negative) ? ((-1)*streamValue) : streamValue;
		targetValue = streamValue;
	}
	
	public StochasticNumber multiply(StochasticNumber sn) {
		boolean[] productStream = new boolean[this.streamLength];
		for(int i = 0; i < this.streamLength; i++) {
			productStream[i] = this.bitStream[i] && sn.bitStream[i];
		}
		return new StochasticNumber(productStream,this.negative^sn.negative);
	}
	
	public StochasticNumber weightedAddition(StochasticNumber sn){
		boolean[] sumStream = new boolean[this.streamLength];
		for(int i=0;i<this.streamLength;i++){
			sumStream[i] = (i%2==0) ? sn.bitStream[i] : this.bitStream[i];
		}
		return new StochasticNumber(sumStream,false);
	}
	
	public double getStreamValue(){
		return streamValue;
	}
	
	public void display() {
		System.out.println("Target Value is: " + targetValue);
		System.out.println("Actual Value is: " + streamValue);
		for(int i = 0; i < streamLength;i++) {
			System.out.print((bitStream[i] ? 1 : 0) + " ");
		}
		System.out.println();
	}
	
	public static void main(String args[]) {
		double a;
		double b;
		double prod;
		StochasticNumber sna;
		StochasticNumber snb;
		StochasticNumber snprod;
		
		for(int j=50; j<1050; j+=50){
			double accuracy = 0;
			for(int i=0;i<1000;i++){
				 a = Math.random();
				 b = Math.random();
				 prod = a*b;
				 sna = new StochasticNumber(a,j);
				 snb = new StochasticNumber(b,j);
				 snprod = sna.multiply(snb);
				 double error = ((Math.abs(snprod.getStreamValue()-prod)/prod)*100);
				 if(error <= 15) accuracy++;
			}
			System.out.println("For "+j+" bits, error is within 15% for "+accuracy/10+"% of the time.");
		}
	}
}