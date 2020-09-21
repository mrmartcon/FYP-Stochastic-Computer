// CMA, DCU, Sept 2019

package JarvisMarch;

import EE324StandardProjectClasses.*;
import java.util.Arrays;

import Arduino.SerialArduino;
import StochasticComputing.*;

public class JarvisMarch {

	///////////////////////
	// getHull
	///////////////////////
	public static Point2D[] getHull(Point2D[] poly) {
		if (poly == null || poly.length < 3)
			throw new IllegalArgumentException("JarvisMarch.getHull() invalid input polygon, null or length < 3.");
		Point2D[] hull = Arrays.copyOf(poly, poly.length);	// copy points to a working array
		int h = 0;											// index of current hull point in array
		swap(hull, initialPointIndex(hull), h); 			// set lowest point as first hull point
		while (true) {
			int cnd = hull.length-1;				// index of candidate for next hull point
			for (int p = h+1; p<hull.length; p++)
				if (turningDirection(hull[h], hull[p], hull[cnd]) < 0)
					cnd = p;
			// check if hull is complete
			if (h == poly.length-1 || turningDirection(hull[h], hull[cnd], hull[0]) > 0) {
				// check if final hull point is colinear and should be excluded
				if (turningDirection(hull[h-1], hull[h], hull[0]) == 0)
					h--;
				break;
			}
			// add the new hull point
			h++;
			swap(hull,cnd,h);
			// remove previous hull point if colinear
			if ((h >= 2)  &&  turningDirection(hull[h-2], hull[h-1], hull[h]) == 0) {
				swap(hull,h,h-1);
				h--;
			}
		};
		// copy hull points to a new array and return it
		return Arrays.copyOf(hull, h+1);
	}
	
	public static Point2D[] stochasticGetHull(Point2D[] poly) {
		if (poly == null || poly.length < 3)
			throw new IllegalArgumentException("JarvisMarch.getHull() invalid input polygon, null or length < 3.");
		Point2D[] hull = Arrays.copyOf(poly, poly.length);	// copy points to a working array
		int h = 0;											// index of current hull point in array
		swap(hull, initialPointIndex(hull), h); 			// set lowest point as first hull point
		while (true) {
			int cnd = hull.length-1;				// index of candidate for next hull point
			for (int p = h+1; p<hull.length; p++)
				if (stochasticTurningDirection(hull[h], hull[p], hull[cnd]) < 0)
					cnd = p;
			// check if hull is complete
			if (h == poly.length-1 || stochasticTurningDirection(hull[h], hull[cnd], hull[0]) > 0) {
				// check if final hull point is colinear and should be excluded
				if (stochasticTurningDirection(hull[h-1], hull[h], hull[0]) == 0)
					h--;
				break;
			}
			// add the new hull point
			h++;
			swap(hull,cnd,h);
			// remove previous hull point if colinear
			if ((h >= 2)  &&  stochasticTurningDirection(hull[h-2], hull[h-1], hull[h]) == 0) {
				swap(hull,h,h-1);
				h--;
			}
		};
		// copy hull points to a new array and return it
		return Arrays.copyOf(hull, h+1);
	}

	///////////////////////
	// swap
	///////////////////////
	private static void swap(Point2D poly[], int i, int j) {
		Point2D pTmp = poly[i];
		poly[i] = poly[j];
		poly[j] = pTmp;
	}

	///////////////////////
	// turningDirection
	///////////////////////
	// turning direction given by sign of z-coordinate of cross-product of p0->p1 and p0->p2
	private static double turningDirection(Point2D p0, Point2D p1, Point2D p2) {
		StochasticNumber a1 = new StochasticNumber((p1.X()-p0.X()), 255);
		StochasticNumber b1 = new StochasticNumber((p1.Y()-p0.Y()), 255);
		StochasticNumber a2 = new StochasticNumber((p2.X()-p0.X()), 255);
		StochasticNumber b2 = new StochasticNumber((p2.Y()-p0.Y()), 255);
		//double target = (p1.X()-p0.X())*(p2.Y()-p0.Y()) - (p1.Y()-p0.Y())*(p2.X()-p0.X());
		double calculated = a1.multiply(b2).getStreamValue() - b1.multiply(a2).getStreamValue();
		//System.out.println("Target: " + target);
		//System.out.println("Calculated: " + calculated);
		return calculated;
	}
	
	private static double stochasticTurningDirection(Point2D p0, Point2D p1, Point2D p2) {
		float x0 = (float) p0.X();
		float y0 = (float) p0.Y();
		float x1 = (float) p1.X();
		float y1 = (float) p1.Y();
		float x2 = (float) p2.X();
		float y2 = (float) p2.Y();
		
		float a = SerialArduino.stochMultiply(x0, y1);
		float b = SerialArduino.stochMultiply(x1, y2);
		float c = SerialArduino.stochMultiply(x2, y0);
		
		float d = SerialArduino.stochMultiply(x0, y2);
		float e = SerialArduino.stochMultiply(x1, y0);
		float f = SerialArduino.stochMultiply(x2, y1);
		
		
		//double target = (p1.X()-p0.X())*(p2.Y()-p0.Y()) - (p1.Y()-p0.Y())*(p2.X()-p0.X());
		double calculated = (a+b+c) - (d+e+f);
		//System.out.println("Target: " + target);
		//System.out.println("Calculated: " + calculated);
		return calculated;
	}

	///////////////////////
	// initialPointIndex
	///////////////////////
	public static int initialPointIndex(Point2D poly[]) {
		if (poly == null || poly.length == 0)
			throw new IllegalArgumentException("JarvisMarch.initialPointIndex() invalid polygon, null or zero length.");
		double minY = Double.MAX_VALUE;
		Point2D minPt = poly[0];
		int idx = -1;
		for (int i=0; i<poly.length; i++) {
			if (poly[i].Y() < minY) {
				minY = poly[i].Y();
				minPt = poly[i];
				idx = i;
			}
			else if (poly[i].Y() == minY  &&  poly[i].X() < minPt.X()) {
				minPt = poly[i];
				idx = i;
			}
		}
		return idx;
	}

}