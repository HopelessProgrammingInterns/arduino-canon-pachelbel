# Advanced Christmas Melody

This is an advanced version of the original Christmas Melody implementation. The two main differences are 1) that it plays a given melody without user input, allowing the user to optinally specify a different duration for each note; and 2) to have multiple arduinos play in sync in a master/slave setup. It also uses the led as a metronome which can help debugging melody and synchronisation problems.

## Architecture

1. There is one master arduino, which outputs a clock signal on the (digital) `MASTER_PIN`. Each tick the signal switches from `HIGH` to `LOW` or vice versa. Each tick signifies a 32nd note.
2. There are any number of slave arduinos who's (digital) `SLAVE_PIN` is connected to the master's `MASTER_PIN` (a slave may be it's own master).
3. The slaves play the next note in their melody, holding it for the required number of ticks.
4. The slaves use the builtin `tone(pin, hz)` function to continuously play the note until `noTone()` is called. `tone()` uses one of the arduinos timer's to generate the sound 'asynchronously' (using interrupts).
5. The master uses the [TimerOne](https://github.com/PaulStoffregen/TimerOne) library to send the clock signal every `n` microseconds (calculated based on the defined BPM), also 'asynchronously' (using interrupts).
6. All `digital(Read|Write)` calls  are replaced by the `digital(Read|Write)Safe` (inline) functions from the [digitalIOPerformance](https://github.com/projectgus/digitalIOPerformance) library, which should be 28 times faster, taking only two cycles instead of 56 ([source](http://www.billporter.info/2010/08/18/ready-set-oscillate-the-fastest-way-to-change-arduino-pins/), tested with a different library but should be comparable) (this works only when the pin number is known at compile time).


