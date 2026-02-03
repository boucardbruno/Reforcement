# Shopping Tunnel

## Context

This application corresponds to the checkout funnel of an international e-commerce website.
 Over time, pricing, tax, and discount rules were added quickly to meet urgent marketing demands (VIP, local promotions, etc.).

The current code is the result of several rapid iterations, often done under pressure, without any real architectural overhaul.

## Issues observed in production

- Final amounts inconsistent depending on the country
- Sporadic errors for some VIP customers
- Frequent regressions when adding a new discount rule
- Inability to write reliable tests without calling external services
- No specific bug is documented, but teams know that “something is wrong”

## Kata objective

- Make price calculation testable
- Isolate business rules from infrastructure code
- Reduce cyclomatic complexity
- Identify and fix a Liskov Substitution Principle violation
- Introduce abstractions without rewriting everything

## Rules

- ❌ Classes annotated with `@DoNotModify` must not be modified
- ❌ No functional removal (existing behavior must be preserved)
- ✅ Final code must be covered by tests
- ✅ Refactoring must be incremental
- ❌ No mocking framework at first (optional later)