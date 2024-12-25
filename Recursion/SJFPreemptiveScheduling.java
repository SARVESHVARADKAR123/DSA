import java.util.*;

class Process {
    int id;       // Process ID
    int arrival;  // Arrival time
    int burst;    // Burst time
    int remaining; // Remaining time
    int completionTime; // Completion time
    int turnaroundTime; // Turnaround time
    int waitingTime;    // Waiting time
    boolean isCompleted; // Whether the process has completed

    Process(int id, int arrival, int burst) {
        this.id = id;
        this.arrival = arrival;
        this.burst = burst;
        this.remaining = burst;
        this.isCompleted = false;
    }
}

public class SJFPreemptiveScheduling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = scanner.nextInt();

        Process[] processes = new Process[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter arrival time for process " + (i + 1) + ": ");
            int arrivalTime = scanner.nextInt();
            System.out.print("Enter burst time for process " + (i + 1) + ": ");
            int burstTime = scanner.nextInt();
            processes[i] = new Process(i + 1, arrivalTime, burstTime);
        }

        executeSJFPreemptive(processes);
        scanner.close();

        // Calculate and display Turnaround Time, Waiting Time, and Average Waiting Time
        calculateAndDisplayTimes(processes);
    }

    private static void executeSJFPreemptive(Process[] processes) {
        int time = 0;
        int completedProcesses = 0;
        int n = processes.length;
        Process currentProcess = null;

        while (completedProcesses < n) {
            // Find the process with the shortest remaining time that has arrived by current time
            Process shortestJob = null;
            for (Process process : processes) {
                if (process.arrival <= time && !process.isCompleted) {
                    if (shortestJob == null || process.remaining < shortestJob.remaining) {
                        shortestJob = process;
                    }
                }
            }

            if (shortestJob != null) {
                currentProcess = shortestJob;
                currentProcess.remaining--;
                time++;

                // If process is finished
                if (currentProcess.remaining == 0) {
                    currentProcess.isCompleted = true;
                    currentProcess.completionTime = time;
                    System.out.println("Process " + currentProcess.id + " completed at time " + time);
                    completedProcesses++;
                }
            } else {
                // If no process has arrived yet, just increase time
                time++;
            }
        }
    }

    private static void calculateAndDisplayTimes(Process[] processes) {
        int totalWaitingTime = 0;
        int totalTurnaroundTime = 0;

        System.out.println("\nProcess | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time");
        for (Process process : processes) {
            process.turnaroundTime = process.completionTime - process.arrival;
            process.waitingTime = process.turnaroundTime - process.burst;

            totalWaitingTime += process.waitingTime;
            totalTurnaroundTime += process.turnaroundTime;

            System.out.println("   " + process.id + "    |     " + process.arrival + "      |     " + process.burst + "      |      " + process.completionTime + "         |      " + process.turnaroundTime + "        |      " + process.waitingTime);
        }

        double averageWaitingTime = (double) totalWaitingTime / processes.length;
        System.out.println("\nAverage Waiting Time: " + averageWaitingTime);
    }
}
