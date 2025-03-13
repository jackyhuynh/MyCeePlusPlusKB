
# Chapter 4 Summary

## Summary
* This chapter focuses on the design of a processor. It begins with an overview of the steps that all instructions must perform: instruction fetch, register read, ALU operation, memory access, and write back.
    * These steps occur in the datapath, which consists of combinational elements and state elements.
    * Control signals determine what operations the datapath should perform.
* A simple single-cycle implementation uses a different datapath element for each step, and control signals are set based on the instruction opcode.
    * While simple, this design is inefficient because the clock cycle must be long enough to accommodate the slowest instruction.
* Pipelining improves performance by overlapping the execution of multiple instructions. [cite: 11099]
    * Instructions move through the five stages of the pipeline: instruction fetch (IF), instruction decode (ID), execute (EX), memory access (MEM), and write back (WB). [cite: 11099]
    * Additional pipeline registers are added between stages to hold the intermediate results. [cite: 11099]
    * Pipelining increases throughput but does not improve the execution time, or latency, of any one instruction. [cite: 11099, 11100]
* Situations when the next instruction cannot execute in the following clock cycle are called hazards.
    * A structural hazard occurs when the hardware cannot support the combination of instructions that are set to execute.
    * A data hazard occurs when an instruction depends on a result from a previous instruction that is not yet available.
    * Forwarding, or bypassing, is a technique to alleviate data hazards by providing results from an earlier stage to a later stage.
    * A load-use data hazard is a specific type of data hazard that occurs when an instruction tries to read a register in the ID stage that a load instruction writes in the WB stage.
    * This hazard cannot be solved with forwarding and requires a pipeline stall, or bubble.
    * A control hazard occurs when a decision must be made regarding the next instruction to fetch, but the decision depends on the result of an instruction that is still in the pipeline.
    * One approach to control hazards is to stall the pipeline until the instruction reaches the MEM stage.
    * Another approach is to predict the outcome of a branch and proceed without stalling.
    * Dynamic branch prediction uses a branch prediction buffer to predict the outcome of a branch.
    * A 1-bit prediction scheme can have a poor prediction accuracy.
    * A 2-bit prediction scheme improves the prediction accuracy by requiring two incorrect predictions before changing the prediction.
    * A third approach to control hazards is a delayed branch, where the instruction immediately following the branch always executes.
    * The MIPS architecture uses a delayed branch.
    * Very deep pipelines and multiple-issue processors use dynamic branch prediction rather than delayed branches.
* Exceptions are similar to control hazards.
    * The instruction causing the exception is stopped, instructions in earlier stages of the pipeline are completed, and instructions in later stages of the pipeline are flushed.
    * The address of the instruction causing the exception is saved in the exception program counter (EPC).
* Hardware can also be designed to increase instruction-level parallelism.
    * Multiple-issue processors can execute multiple instructions in a clock cycle.
    * Static multiple-issue processors rely on the compiler to schedule instructions to avoid hazards.
    * Dynamic multiple-issue processors decide at runtime which instructions to execute.
    * Dynamic scheduling uses reservation stations to buffer operands and functional units.
    * Register renaming is used to remove antidependences.
    * Instructions are issued in-order, but may complete out-of-order.
    * Speculation is used to further improve ILP by allowing execution to begin before knowing the outcome of a branch or load.
    * Hardware must provide a mechanism to recover from incorrect speculation.
* The Intel Core i7 is an example of a processor with a deep pipeline, dynamic multiple issue, dynamic scheduling, and speculation.

## Reference:

- Patterson, D. A., & Hennessy, J. L. (2014). Computer organization and design: The hardware/soft ware interface. Fifth edition. Waltham, MA: Morgan Kaufmann. 