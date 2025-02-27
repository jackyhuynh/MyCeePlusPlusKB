<h1>Compilation Process</h1>
<details>
  <summary>How High-Level Languages (C, Java) Are Translated into Machine Code</summary>
  <h1>How High-Level Languages (C, Java) Are Translated into Machine Code</h1>
  <p>High-level programming languages like <strong>C and Java</strong> are not directly understood by a computer’s CPU. Instead, they need to be translated into <strong>machine code</strong> (binary instructions) that the processor can execute. This translation process happens in multiple steps, involving <strong>compilers, assemblers, and linkers</strong>.</p>

  <h2>1. Compilation Process (C Language)</h2>
  <h3>Step 1: Preprocessing</h3>
  <p>The <strong>preprocessor</strong> handles directives (like <code>#include</code> and <code>#define</code>) and expands macros.</p>
  <pre><code>#include <stdio.h>
#define PI 3.14

int main() {
    printf("Value of PI: %f\n", PI);
    return 0;
}</code></pre>

  <h3>Step 2: Compilation</h3>
  <p>The compiler (e.g., <code>gcc</code> or <code>clang</code>) converts preprocessed C code into assembly language.</p>
  <pre><code>mov eax, 3
add eax, 5</code></pre>

  <h3>Step 3: Assembly</h3>
  <p>The assembler converts the assembly code into <strong>machine code (binary)</strong>.</p>
  <pre><code>10110000 00000011 00000000 00000101</code></pre>

  <h3>Step 4: Linking</h3>
  <p>The <strong>linker</strong> combines object files and necessary libraries, generating the final executable.</p>
  <pre><code>gcc program.o -o program</code></pre>

</details>

<details>
  <summary>How Does GCC Compile Code So Fast?</summary>
  <h1>How Does GCC Compile Code So Fast?</h1>
  <p>The <strong>GNU Compiler Collection (GCC)</strong> is designed for efficiency, using <strong>optimizations, multi-stage processing, and parallel execution</strong> to compile code quickly.</p>

  <h2>GCC Compilation Process Flowchart</h2>
  <ol>
    <li>Source Code (<code>.c/.cpp</code>)</li>
    <li>Preprocessing (<code>cpp</code>) – Expands macros, includes header files</li>
    <li>Compilation (<code>cc1</code>) – Converts source code to assembly (<code>.s</code> file)</li>
    <li>Assembly (<code>as</code>) – Translates assembly to machine code (<code>.o</code> file)</li>
    <li>Linking (<code>ld</code>) – Combines object files, resolves dependencies</li>
    <li>Executable File (<code>.out/.exe</code>) – Final runnable program</li>
  </ol>

  <h2>1. Stages of GCC Compilation</h2>
  <table border="1">
    <tr><th>Stage</th><th>Tool</th><th>Description</th></tr>
    <tr><td>Preprocessing</td><td><code>cpp</code></td><td>Expands macros and <code>#include</code> files.</td></tr>
    <tr><td>Compilation</td><td><code>cc1</code></td><td>Translates C into assembly code.</td></tr>
    <tr><td>Assembly</td><td><code>as</code></td><td>Converts assembly into machine code.</td></tr>
    <tr><td>Linking</td><td><code>ld</code></td><td>Combines object files into an executable.</td></tr>
  </table>

  <h2>2. Why Is GCC So Fast?</h2>
  <ul>
    <li><strong>Optimized Code Paths</strong> – Built-in compiler optimizations like <code>-O2</code> or <code>-O3</code>.</li>
    <li><strong>Parallel Compilation</strong> – Uses multiple CPU cores with <code>make -j</code>.</li>
    <li><strong>Precompiled Headers</strong> – Caches headers to avoid redundant work.</li>
    <li><strong>Incremental Compilation</strong> – Skips recompilation of unchanged files.</li>
    <li><strong>Efficient Optimization Algorithms</strong> – Dead code elimination, loop unrolling, and constant propagation.</li>
  </ul>
</details>
