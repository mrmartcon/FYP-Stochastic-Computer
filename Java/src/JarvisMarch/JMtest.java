package JarvisMarch;

//CMA, DCU, Sept 2019

import java.awt.Color;
import EE324StandardProjectClasses.Point2D;
import EE324StandardProjectClasses.TestPolygonGenerator;
import edu.princeton.cs.introcs.StdDraw;

public class JMtest {

	////////////////////////////
	// TEST CLIENT
	////////////////////////////
	public static void main(String[] args)
	{
		// Test hull of collinear1 points
		setupCanvas();
		Point2D[] inputPoints = TestPolygonGenerator.collinear1();
		Point2D p0 = inputPoints[JarvisMarch.initialPointIndex(inputPoints)];
		drawPolyPoints(inputPoints, Color.PINK);
		StdDraw.pause(500);
		Point2D[] hull = JarvisMarch.getHull(TestPolygonGenerator.collinear1());
		drawPolyEdges(hull);
		drawPolyPoints(hull, Color.RED);
		StdDraw.pause(1000);

		// Test hull of collinear2 points
		setupCanvas();
		inputPoints = TestPolygonGenerator.collinear2();
		p0 = inputPoints[JarvisMarch.initialPointIndex(inputPoints)];
		drawPolyPoints(inputPoints, Color.PINK);
		StdDraw.pause(500);
		hull = JarvisMarch.getHull(TestPolygonGenerator.collinear2());
		drawPolyEdges(hull);
		drawPolyPoints(hull, Color.RED);
		StdDraw.pause(1000);
		
		// Test hull with random input points
		for (int i=0; i<10; i++) {
			setupCanvas();

			Point2D[] pg = TestPolygonGenerator.randomPolyGaussian(25);
			p0 = pg[JarvisMarch.initialPointIndex(pg)];
			drawPolyPoints(pg, Color.PINK);
			StdDraw.pause(500);

			Point2D[] h = JarvisMarch.getHull(pg);
			drawPolyEdges(h);
			drawPolyPoints(h, Color.RED);
			StdDraw.pause(1000);
		}

	}

	//////////////////////////////////
	// Auxiliary drawing methods
	//////////////////////////////////

	private static void drawPolyEdges(Point2D[] poly) {
		for (int k=0; k<poly.length; k++) {
			poly[k].drawTo(poly[(k+1) % poly.length], Color.BLUE, 0.004);
		}
	}

	public static void drawPolyPoints(Point2D[] poly, Color clr) {
		for (int k=0; k<poly.length; k++) {
			poly[k].draw(clr, 0.018);
		}
	}

	public static void setupCanvas() {
		StdDraw.setCanvasSize(500, 500);
		StdDraw.setScale(-.05, 1.05);
	}
}