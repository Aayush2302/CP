// <!-- Include in index.html just before </body> -->
document.getElementById("schedulingForm").addEventListener("submit", async (e) => {
    e.preventDefault();

    const pid = e.target.pid.value;
    const arrivalTime = e.target.arrivalTime.value;
    const burstTime = e.target.burstTime.value;
    const algorithm = e.target.algorithm.value;

    const response = await fetch("http://localhost:3000/simulate", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({
            process: { pid, arrivalTime, burstTime },
            algorithm
        })
    });

    const result = await response.json();
    renderGantt(result);
});

function renderGantt(data) {
    const ctx = document.getElementById("ganttChart").getContext("2d");
    const labels = data.map(p => `P${p.pid}`);
    const durations = data.map(p => p.burstTime);

    new Chart(ctx, {
        type: 'bar',
        data: {
            labels,
            datasets: [{
                label: "Gantt Chart",
                data: durations,
                backgroundColor: 'rgba(54, 162, 235, 0.6)',
                borderColor: 'rgb(54, 162, 235)',
                borderWidth: 1,
                barPercentage: 1,
                categoryPercentage: 1
            }]
        },
        options: {
            indexAxis: 'y',
            plugins: {
                legend: { display: false }
            },
            responsive: true,
            scales: {
                x: {
                    beginAtZero: true,
                    stacked: true
                },
                y: {
                    stacked: true
                }
            }
        }
    });
}
<canvas id="ganttChart" width="600" height="400" class="mt-10"></canvas>
