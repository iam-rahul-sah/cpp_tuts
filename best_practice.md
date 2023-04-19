# Best Practice

## Control Statement and Error handling

- *Prefer `switch statement` over `if-else` statement when there is a choice*  
- *Place the `default` case last in the `switch statement`*
- *Each set of statement underneath a label should end in a `break` statement or a `return` statement. This include the statement underneath the last label in the switch.*
- *Use the `[[fallthrough]]` attribute(along with a null statement) to indicate that fallthrough is intentional*
- *If defining variables used in a case statement, do so in a block inside the case statement*
-