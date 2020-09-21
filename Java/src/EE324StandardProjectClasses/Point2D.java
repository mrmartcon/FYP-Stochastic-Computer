package EE324StandardProjectClasses;
import edu.princeton.cs.introcs.StdDraw;
import java.awt.Color;
import java.awt.Font;

/**
 * A simple 2D point class with drawing methods.
 * <p><b>NOTE:</b> This class requires Sedgewick's and Wayne's StdDraw library.<br>
 * <a href="https://introcs.cs.princeton.edu/java/stdlib/stdlib-package.jar">https://introcs.cs.princeton.edu/java/stdlib/stdlib-package.jar</a>
 * @author Conor McArdle (conor.mcardle@dcu.ie)
 */
public class Point2D {

	private final double x;
	private final double y;

	/** Construct a point with given x and y coordinate values.
	 * @param x coordinate of point
	 * @param y coordinate of point
	 */
	public Point2D(double x, double y) {
		this.x = x;
		this.y = y;
	}

	/** Copy constructor - makes a copy of the specified point.
	 * @param p point to copy
	 */
	public Point2D(Point2D p) {
		if (p == null)
			throw new IllegalArgumentException("Point2D cannot be null in copy constructor.");
		x = p.x;
		y = p.y;
	}

	/** Get x-coordinate of this point.
	 * @return x coordinate of point
	 * */
	public double X() {
		return x;
	}

	/** Get y-coordinate of this point.
	 * @return y coordinate of point
	 */
	public double Y() {
		return y;
	}

	/** Test if this point is coincident with another point p.
	 * @param p point to compare this point to
	 * @return true if points have same coordinates, false otherwise
	 */
	public boolean isEqual(Point2D p) {
		return (p.x == x) && (p.y == y);
	}

	/** Distance from this point to another point p.
	 * @param p other point
	 * @return distance from this point to other point
	 * */
	public double distanceTo(Point2D p) {
		return Math.sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
	}

	/** Get mid-point of this point and another point p.
	 * @param p other point
	 * @return new point which is mid-point between this point and p
	 */
	public Point2D midPoint(Point2D p) {
		return new Point2D((x+p.x)/2, (y+p.y)/2);
	}

	/** Get string representation of this point in the form "(x,y)".
	 * @return string representation of this point
	 */
	@Override
	public String toString() {
		return ("(" + x + "," + y + ")");
	}

	/** Draw this point using the current StdDraw color and pen width.
	 * Uses the StdDraw library.
	 */
	public void draw() {
		StdDraw.point(x, y);
	}

	/** Draw this point with a specified color. Uses the StdDraw library.
	 * @param clr the pen color to use
	 */
	public void draw(Color clr) {
		Color savedColor = StdDraw.getPenColor();
		StdDraw.setPenColor(clr);
		this.draw();
		StdDraw.setPenColor(savedColor);
	}

	/** Draw this point with a specified color and pen width. Uses the StdDraw library.
	 * @param clr the pen color to use
	 * @param penWidth width of the pen to use
	 */
	public void draw(Color clr, double penWidth) {
		double savedPenWidth = StdDraw.getPenRadius();
		StdDraw.setPenRadius(penWidth);
		this.draw(clr);
		StdDraw.setPenRadius(savedPenWidth);
	}

	/** Draw a line from this point to anther point p using the current StdDraw color and pen width.
	 * Uses the StdDraw library.
	 * @param p other point
	 * */
	public void drawTo(Point2D p) {
		StdDraw.line(x, y, p.x, p.y);
	}

	/** Draw a line from this point to anther point p using a specified color. Uses the StdDraw library.
	 * @param p the point to draw
	 * @param clr the pen color to use
	 */
	public void drawTo(Point2D p, Color clr) {
		Color savedColor = StdDraw.getPenColor();
		StdDraw.setPenColor(clr);
		this.drawTo(p);
		StdDraw.setPenColor(savedColor);
	}

	/** Draw a line from this point to anther point p using a specified color and pen width. Uses the StdDraw library. 
	 * @param p the point to draw
	 * @param clr the pen color to use
	 * @param penWidth width of the pen to use
	 */
	public void drawTo(Point2D p, Color clr, double penWidth) {
		double savedPenWidth = StdDraw.getPenRadius();
		StdDraw.setPenRadius(penWidth);
		this.drawTo(p, clr);
		StdDraw.setPenRadius(savedPenWidth);
	}

	/** Demonstrator for the Point2D class. Constructs and draws a regular polygon.
	 * @param numSides number of sides of polygon
	 * @exception IllegalArgumentException if numSides is less than 3
	 */
	public static void polyDemo(int numSides) {
		if (numSides < 3)
			throw new IllegalArgumentException("Point2D_Demo() specify minimum of 3 sides of polygon to draw");
		// construct the points of the polygon
		Point2D[] polygon = new Point2D[numSides];
		for (int i=0; i<numSides; i++)
			polygon[i] = new Point2D(Math.sin(i*2*Math.PI/numSides), Math.cos(i*2*Math.PI/numSides));
		// setup the drawing canvas
		StdDraw.setCanvasSize(700, 700);
		StdDraw.setScale(-1.3, 1.3);
		Font font = new Font("ARIAL", Font.BOLD, 25);
		StdDraw.setFont(font);
		StdDraw.text(0, 1.15, "Point2D Tester");
		StdDraw.text(0,-1.15, Integer.toString(numSides) + "-sided regular polygon");
		// draw the polygon's sides and angles
		for (int i=0; i<numSides; i++) {
			polygon[i].drawTo(polygon[(i+1) % numSides], Color.BLACK, 0.005);
			polygon[i].drawTo(new Point2D(0,0), new Color(0.8f,0.8f,0.8f), 0.003);
		}
		// draw the polygon's points
		for (int i=0; i<numSides; i++)
			polygon[i].draw(Color.BLUE, 0.025);
	}

}