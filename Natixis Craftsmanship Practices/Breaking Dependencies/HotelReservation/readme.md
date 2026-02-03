# Hotel Reservation

## Context

This module belongs to a hotel booking engine used by several partners.
 It determines whether a reservation can be accepted based on multiple criteria (duration, number of guests, hotel score, time of day, etc.).

Over the years, rules have been added by different teams, without any global documentation.

## Issues observed in production

- Reservations rejected without a clear reason
- Different behaviors depending on execution time
- Partners complaining about non-reproducible results
- Any code change creates fear of breaking something else

## Kata objective

- Understand a complex and deeply nested business algorithm
- Separate business decision logic from external dependencies
- Reduce dependency on system time
- Make the rules readable and testable
- Prepare the ground for future evolution

## Rules

- ❌ Classes annotated with `@DoNotModify` must not be modified
- ✅ Unit tests are mandatory
- ✅ Existing behavior must be preserved (characterization tests recommended)
- ❌ No arbitrary simplification of business rules