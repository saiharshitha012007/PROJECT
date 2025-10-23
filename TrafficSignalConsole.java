public class TrafficSignalConsole {
 enum LightState { RED, YELLOW, GREEN }
 public static void main(String[] args) {
 LightState northSouth = LightState.GREEN;
 LightState eastWest = LightState.RED;
 int greenDuration = 5000; // 5 seconds
 int yellowDuration = 2000; // 2 seconds
 System.out.println("=== TRAFFIC SIGNAL SIMULATION (CONSOLE) ===\n");
 for (int i = 0; i < 3; i++) { // Runs for 3 full cycles
 northSouth = LightState.GREEN;
 eastWest = LightState.RED;
 printStatus(northSouth, eastWest);
 sleep(greenDuration);
 northSouth = LightState.YELLOW;
 eastWest = LightState.RED;
 printStatus(northSouth, eastWest);
 sleep(yellowDuration);
 northSouth = LightState.RED;
 eastWest = LightState.GREEN;
 printStatus(northSouth, eastWest);
 sleep(greenDuration);
 northSouth = LightState.RED;
 eastWest = LightState.YELLOW;
 printStatus(northSouth, eastWest);
 sleep(yellowDuration);
 }
 }
 static void printStatus(LightState ns, LightState ew) {
 System.out.println("------------------------------------------");
 System.out.println("North–South Signal: " + ns);
 System.out.println("East–West Signal: " + ew);
 System.out.println("------------------------------------------\n");
 }
 static void sleep(int ms) {
 try {
 Thread.sleep(ms);
 } catch (InterruptedException e) {
 Thread.currentThread().interrupt();
 }
 }
}
