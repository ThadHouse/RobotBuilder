// ${version-indicator}

package ${package};
    
${helper.getImports($robot, "RobotMap")}
import edu.wpi.first.wpilibj.livewindow.LiveWindow;
import java.util.Vector;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
public class RobotMap {
#foreach ($component in $components)
#if ($helper.exportsTo("RobotMap", $component))
    #declaration($component)

#end
#end

    public static void init() {
#foreach ($component in $components)
#if ($helper.exportsTo("RobotMap", $component))
        #constructor($component)

	#livewindow($component)

        #extra($component)

#end
#end
    }
}