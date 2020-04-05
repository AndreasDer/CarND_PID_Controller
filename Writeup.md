## Reflection

#### Effects of P-, I- and D-component

The biggest effect on the behavior of the car has the P-component of the controller along with the D-component of the controller. Nearly no effect is achieved by the I-component of the controller.
The P-component is responsible for reaction proportional to the error. the bigger the error, the bigger is the resulting correction. It has high tendencies to overshoot.
The I-component is responsible to compensate for system errors. For example if the car always over steers in one direction, this can be compensated by the I-component.
The D-component is damping the behavior of the P-component as it reacts to the difference in error. Meaning if the error correction is high because of the P-component, the damping also gets higher which leads to a smoother behavior of the controller.

#### Tuning of parameters

To tune the parameters of the controller I implemented the Twiddle algorithm. The resulting parameters of twiddle for a speed of 30 mph are shown in the table below.

| Component | Value    |
| --------- | -------- |
| P         | 0.214519 |
| I         | 0.275214 |
| D         | 7.187    |

#### Result

The result of my controllers behavior can be seen in the video [Video](https://github.com/AndreasDer/CarND_PID_Controller/blob/master/output/self_driving_car_nanodegree_program%202020-04-04%2018-38-18.mp4)

#### Conclusion

Tuning a single controller that can handle all the different situations is not possible as there are too many factors that influence the behavior. For example, if the controller is optimized for straight parts of the tracks it would behave very bad in the curved parts and vice versa.
Also the speed is another factor that influences the result of the control parameter. The faster we go, the lower our controller parameter has to be.
To have a car that can go at different speeds on different tracks more than one controller is needed and a kind of situation understanding and choosing the right controller would be necessary.