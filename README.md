#Cooperative robot platooning 
Team: Angela Dong, Francis Leary, Wendi Luan, Qingrong Zhou
EECS 149/249A Project Proposal, Fall 2019

Goals
Wirelessly coordinate multiple Kobuki+buckler robots to follow the leader.

Approach
The project will model relative location and velocity to maintain a formation of Kobuki robots. The goal is to maintain formation despite obstacles, and counteract sensor drift with absolute ranging.

Resources
We will use the Buckler and Kobuki as our platform. We will use BLE to coordinate movements, accelerometers to verify movements, and bump sensors to avoid obstacles. We will use ultra-wide band time of flight for two way ranging. Bump sensors onboard Kobuki will be used for obstacle avoidance. 
The next step will be to find distance and approximate direction with the TWR capabilities of the DWM1001. According to the datasheet, ranging accuracy is within 10cm. This will allow for finding approximate direction to a static transceiver by rotating the Kobuki and minimizing distance.
Finally, we will need to implement some control to correct for drift and change or maintain formation.

Schedule
• October 25: Project charter (this document)
• November 1: Statecharts simulation model with logic and timing for controller.
• November 8: Milestone 1: Get DWM1001 and Buckle connected. Establish BLE connection between leader Kobuki and non-leading Kobukis.
• November 15:  Get accurate distances and find the approximate direction without obstacles
• November 17: Milestone 2
• November 22: Avoid obstacles while following the leader Kobuki
• November 29: Establish connections among non-leading Kobukis and make them follow the leader Kobuki without bumping to each other.
• December 6: Testing, robustness. 
• December 17: Demonstration video and poster made, powerpoint prepared. Project Expo.
• December 20: Final report


Risks/Feasibility
We already know how to control the Kobuki and communicate over BLE, basic coordination should be feasible. Risks are in the reliability of coordination as the probability of success will depend on each link in the chain succeeding. UWB TWR may reveal some issues if we can’t get the accuracy or reliability we need.
